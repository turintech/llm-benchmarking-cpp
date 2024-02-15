#include "matrixalgebra.h"
#include <stdexcept>

/** @brief Multiply a matrix with a vector
 *
 * @param a Matrix shape(adim0, adim1)
 * @param x Vector shape(xdim)
 *
 * @return Product of a and b, shape(adim0)
 */
std::vector<double>
MathMatrixAlgebra::MatrixMultiply(const std::vector<std::vector<double>> &a, const std::vector<double> &x) {
  int adim0 = a.size();
  int adim1 = a[0].size();
  int xdim = x.size();

  std::vector<double> result(adim0, 0.0);

  if (adim1 != xdim) {
    throw std::invalid_argument("Matrix dimensions don't match for multiplication");
  }

  for (int i = 0; i < adim0; i++) {
    for (int j = 0; j < xdim; j++) {
      result[i] += a[i][j] * x[j];
    }
  }

  return result;
}

/** @brief Multiply two matrices
 *
 * @param a First matrix shape(adim0, adim1)
 * @param b Second matrix shape(bdim0, bdim1)
 *
 * @return Product of a and b, shape(adim0, bdim1)
 */
std::vector<std::vector<double>>
MathMatrixAlgebra::MatrixMultiply(const std::vector<std::vector<double>> &a,
                                  const std::vector<std::vector<double>> &b) {
  int adim0 = a.size();
  int adim1 = a[0].size();
  int bdim0 = b.size();
  int bdim1 = b[0].size();

  std::vector<std::vector<double>> result(adim0, std::vector<double>(bdim1, 0.0));

  if (adim1 != bdim0) {
    throw std::invalid_argument("Matrix dimensions don't match for multiplication");
  }

  for (int i = 0; i < adim0; i++) {
    for (int j = 0; j < bdim1; j++) {
      for (int k = 0; k < adim1; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return result;
}

/** @brief Rotates a series of points by a matrix
 *
 * @param a Points shape(npoints, ndim)
 * @param b Rotation matrix shape(ndim, ndim)
 *
 * @return Updated Point Locations shape(ndim, npoints)
 */
std::vector<std::vector<double>>
MathMatrixAlgebra::RotatePoints(const std::vector<std::vector<double>> &points,
                                const std::vector<std::vector<double>> &rotmat) {
  int npoints = points.size();
  int ndim = points[0].size();

  if ((ndim != rotmat.size()) || (ndim != rotmat[0].size())) {
    throw std::invalid_argument("Rotation matrix dimensions don't match to points");
  }

  std::vector<std::vector<double>> result(npoints, std::vector<double>(ndim, 0.0));

  for (int i = 0; i < npoints; i++) {
    result[i] = MatrixMultiply(rotmat, points[i]);
  }

  return result;
}

std::vector<double>
MathMatrixAlgebra::LinearSolver(const std::vector<std::vector<double>> &equations, const std::vector<double> &inputs) {
  std::vector<std::vector<double>> L;
  std::vector<std::vector<double>> U;

  LuDecompose(equations, L, U);
  std::vector<double> y = ForwardSubstitution(L, inputs);
  std::vector<double> x = BackwardSubstitution(U, y);
  return x;
}

void
MathMatrixAlgebra::LuDecompose(const std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &L,
                               std::vector<std::vector<double>> &U) {
  if (A.size() != A[0].size()) {
    throw std::invalid_argument("A needs to be square");
  }

  int n = A.size();

  L = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));
  U = std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0));

  for (int i = 0; i < n; i++) {
    // Upper Triangular
    for (int k = i; k < n; k++) {
      double sum = 0.0;
      for (int j = 0; j < i; j++) {
        sum += L[i][j] * U[j][k];
      }
      U[i][k] = A[i][k] - sum;
    }

    // Lower Triangular
    for (int k = i; k < n; k++) {
      if (i == k)
        L[i][i] = 1.0;
      else {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
          sum += L[k][j] * U[j][i];
        }
        L[k][i] = (A[k][i] - sum) / U[i][i];
      }
    }
  }
}

std::vector<double>
MathMatrixAlgebra::ForwardSubstitution(const std::vector<std::vector<double>> &L, const std::vector<double> &b) {
  if (L.size() != L[0].size()) {
    throw std::invalid_argument("L needs to be square");
  }
  if (L.size() != b.size()) {
    throw std::invalid_argument("L dimensions don't match to b");
  }

  int n = L.size();

  std::vector<double> y(n, 0.0);

  for (int i = 0; i < n; i++) {
    y[i] = b[i];
    for (int j = 0; j < i; j++) {
      y[i] = y[i] - L[i][j] * y[j];
    }
    if (L[i][i] == 0) {
      throw std::invalid_argument("L needs to be non-singular");
    }
    y[i] = y[i] / L[i][i];
  }

  return y;
}

std::vector<double>
MathMatrixAlgebra::BackwardSubstitution(const std::vector<std::vector<double>> &U, const std::vector<double> &y) {
  if (U.size() != U[0].size()) {
    throw std::invalid_argument("U needs to be square");
  }
  if (U.size() != y.size()) {
    throw std::invalid_argument("U dimensions don't match to y");
  }

  int n = U.size();

  std::vector<double> x(n, 0.0);

  for (int i = n - 1; i >= 0; i--) {
    x[i] = y[i];
    for (int j = i + 1; j < n; j++) {
      x[i] = x[i] - U[i][j] * x[j];
    }
    if (U[i][i] == 0) {
      throw std::invalid_argument("L needs to be non-singular");
    }
    x[i] = x[i] / U[i][i];
  }

  return x;
}
