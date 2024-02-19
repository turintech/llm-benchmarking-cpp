#ifndef __MATH_MATRIXALGEBRA_H__
#define __MATH_MATRIXALGEBRA_H__

#include <vector>

// Convenience includes for artemis
#if __has_include(<CL/sycl.hpp>)
#include <CL/sycl.hpp>
#endif   // __has_include

namespace MathMatrixAlgebra {

std::vector<double> MatrixMultiply(const std::vector<double> &a, int nAI, int nAJ, const std::vector<double> &x,
                                   int nXI);
std::vector<double> MatrixMultiply(const std::vector<double> &a, int nAI, int nAJ, const std::vector<double> &b,
                                   int nBI, int nBJ);
std::vector<double> RotatePoints(const std::vector<double> &points, int nPoints, int nDim,
                                 const std::vector<double> &rotmat);
std::vector<double> LinearSolver(const std::vector<double> &equations, const std::vector<double> &inputs, int nI);
void LuDecompose(const std::vector<double> &A, std::vector<double> &L, std::vector<double> &U, int nI);
std::vector<double> ForwardSubstitution(const std::vector<double> &L, const std::vector<double> &b, int nI);
std::vector<double> BackwardSubstitution(const std::vector<double> &U, const std::vector<double> &y, int nI);
std::vector<double> Convolve2D(const std::vector<double> &a, int nAI, int nAJ, const std::vector<double> &k, int nKI,
                               int nKJ, int padding, int stride);

};   // namespace MathMatrixAlgebra

#endif   // !__MATH_MATRIXALGEBRA_H__
