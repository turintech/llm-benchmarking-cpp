#include "matrixalgebra.h"
#include <stdexcept>

/** @brief Multiply a matrix with a vector
 *
 * @param a Matrix shape(nAI, nAJ)
 * @param x Vector shape(nXI)
 *
 * @return Product of a and b, shape(nAI)
 */
std::vector<double>
MathMatrixAlgebra::MatrixMultiply(const std::vector<double> &a, int nAI, int nAJ, const std::vector<double> &x,
                                  int nXI) {
  std::vector<double> result(nAI, 0.0);

  if (nXI != x.size()) {
    throw std::invalid_argument("Vector dimensions don't match for `x`");
  }
  if (nAI * nAJ != a.size()) {
    throw std::invalid_argument("Matrix dimensions don't match for `a`");
  }
  if (nAJ != nXI) {
    throw std::invalid_argument("Matrix dimensions don't match for multiplication");
  }

  for (int i = 0; i < nAI; i++) {
    for (int j = 0; j < nXI; j++) {
      result[i] += a[i * nAJ + j] * x[j];
    }
  }

  return result;
}

/** @brief Multiply two matrices
 *
 * @param a First matrix shape(nAI, nAJ)
 * @param b Second matrix shape(nBI, nBJ)
 *
 * @return Product of a and b, shape(nAI, nBJ)
 */
std::vector<double>
MathMatrixAlgebra::MatrixMultiply(const std::vector<double> &a, int nAI, int nAJ, const std::vector<double> &b, int nBI,
                                  int nBJ) {
  std::vector<double> result(nAI * nBJ, 0.0);

  if (nAI * nAJ != a.size()) {
    throw std::invalid_argument("Matrix dimensions don't match for `a`");
  }
  if (nBI * nBJ != b.size()) {
    throw std::invalid_argument("Matrix dimensions don't match for `b`");
  }
  if (nAJ != nBI) {
    throw std::invalid_argument("Matrix dimensions don't match for multiplication");
  }

  for (int i = 0; i < nAI; i++) {
    for (int j = 0; j < nBJ; j++) {
      for (int k = 0; k < nAJ; k++) {
        result[i * nBJ + j] += a[i * nAJ + k] * b[k * nBJ + j];
      }
    }
  }

  return result;
}

/** @brief Rotates a series of points by a matrix
 *
 * @param a Points shape(nPoints, nDim)
 * @param b Rotation matrix shape(nDim, nDim)
 *
 * @return Updated Point Locations shape(nDim, nPoints)
 */
std::vector<double>
MathMatrixAlgebra::RotatePoints(const std::vector<double> &points, int nPoints, int nDim,
                                const std::vector<double> &rotmat) {
  if (nPoints * nDim != points.size()) {
    throw std::invalid_argument("Matrix dimensions don't match for `points`");
  }
  if (nDim * nDim != rotmat.size()) {
    throw std::invalid_argument("Matrix dimensions don't match for `rotmat`");
  }

  std::vector<double> result(nPoints * nDim, 0.0);
  std::vector<double> tmpPoint(nDim, 0.0);

  for (int i = 0; i < nPoints; i++) {
    for (int j = 0; j < nDim; j++) {
      tmpPoint[j] = points[i * nDim + j];
    }

    std::vector<double> rotPoint = MatrixMultiply(rotmat, nDim, nDim, tmpPoint, nDim);

    for (int j = 0; j < nDim; j++) {
      result[i * nDim + j] = rotPoint[j];
    }
  }

  return result;
}

/** @brief Solves a set of linear equations
 *
 * @NOTE this doesn't handle many of the edge cases
 * @param equations, the equations as a flattened vector, shape (nI, nI)
 * @param inputs, the input values (solutions to the linear equations), shape (nI)
 * @param nI, the number of equations
 *
 * @return x, the unknowns of the linear equations
 */
std::vector<double>
MathMatrixAlgebra::LinearSolver(const std::vector<double> &equations, const std::vector<double> &inputs, int nI) {
  std::vector<double> L;
  std::vector<double> U;

  LuDecompose(equations, L, U, nI);
  std::vector<double> y = ForwardSubstitution(L, inputs, nI);
  std::vector<double> x = BackwardSubstitution(U, y, nI);
  return x;
}

/** @brief LU Decomposition algorithm without pivoting (doolittle)
 *
 * @param A input matrix
 * @param L output lower triangular (to be initialised in this function)
 * @param U output upper triangular (to be initialised in this function)
 */
void
MathMatrixAlgebra::LuDecompose(const std::vector<double> &A, std::vector<double> &L, std::vector<double> &U, int nI) {
  if (nI * nI != A.size()) {
    throw std::invalid_argument("invalid dimensions for `A`");
  }

  L = std::vector<double>(nI * nI, 0.0);
  U = std::vector<double>(nI * nI, 0.0);

  for (int i = 0; i < nI; i++) {
    // Upper Triangular
    for (int k = i; k < nI; k++) {
      double sum = 0.0;
      for (int j = 0; j < i; j++) {
        sum += L[i * nI + j] * U[j * nI + k];
      }
      U[i * nI + k] = A[i * nI + k] - sum;
    }

    // Lower Triangular
    for (int k = i; k < nI; k++) {
      if (i == k)
        L[i * nI + i] = 1.0;
      else {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
          sum += L[k * nI + j] * U[j * nI + i];
        }
        L[k * nI + i] = (A[k * nI + i] - sum) / U[i * nI + i];
      }
    }
  }
}

std::vector<double>
MathMatrixAlgebra::ForwardSubstitution(const std::vector<double> &L, const std::vector<double> &b, int nI) {
  if (nI * nI != L.size()) {
    throw std::invalid_argument("invalid dimensions for `L`");
  }
  if (nI != b.size()) {
    throw std::invalid_argument("invalid dimension for `b`");
  }

  std::vector<double> y(nI, 0.0);

  for (int i = 0; i < nI; i++) {
    y[i] = b[i];
    for (int j = 0; j < i; j++) {
      y[i] = y[i] - L[i * nI + j] * y[j];
    }
    if (L[i * nI + i] == 0) {
      throw std::invalid_argument("L needs to be non-singular");
    }
    y[i] = y[i] / L[i * nI + i];
  }

  return y;
}

std::vector<double>
MathMatrixAlgebra::BackwardSubstitution(const std::vector<double> &U, const std::vector<double> &y, int nI) {
  if (nI * nI != U.size()) {
    throw std::invalid_argument("invalid dimensions for `U`");
  }
  if (nI != y.size()) {
    throw std::invalid_argument("invalid dimension for `y`");
  }

  std::vector<double> x(nI, 0.0);

  for (int i = nI - 1; i >= 0; i--) {
    x[i] = y[i];
    for (int j = i + 1; j < nI; j++) {
      x[i] = x[i] - U[i * nI + j] * x[j];
    }
    if (U[i * nI + i] == 0) {
      throw std::invalid_argument("L needs to be non-singular");
    }
    x[i] = x[i] / U[i * nI + i];
  }

  return x;
}

/** @brief Convolution in 2D
 *
 * @param a, the input vector. Shape (nAI, nAJ).
 * @param k, the kernel. Shape (nKI, nKJ).
 * @param padding
 * @param stride
 *
 * @return b, the output vector. Shape (nBI, nBJ)
 */
std::vector<double>
MathMatrixAlgebra::Convolve2D(const std::vector<double> &a, int nAI, int nAJ, const std::vector<double> &k, int nKI,
                              int nKJ, int padding, int stride) {
  if (nAI * nAJ != a.size()) {
    throw std::invalid_argument("invalid dimensions for `a`");
  }
  if (nKI * nKJ != k.size()) {
    throw std::invalid_argument("invalid dimensions for `k`");
  }

  int nBI = (nAI - nKI + 2 * padding) / stride + 1;
  int nBJ = (nAJ - nKJ + 2 * padding) / stride + 1;
  std::vector<double> b(nBI * nBJ, 0.0);

  for (int y = 0; y < nBI; ++y) {
    for (int x = 0; x < nBJ; ++x) {
      double sum = 0.0;
      for (int ky = 0; ky < nKI; ++ky) {
        for (int kx = 0; kx < nKJ; ++kx) {
          int iy = y * stride + ky - padding;
          int ix = x * stride + kx - padding;
          if (iy >= 0 && iy < nAI && ix >= 0 && ix < nAJ) {
            sum += a[iy * nAJ + ix] * k[ky * nKJ + kx];
          }
        }
      }
      b[y * nBJ + x] = sum;
    }
  }

  return b;
}
