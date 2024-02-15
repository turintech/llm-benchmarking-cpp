#ifndef __MATH_MATRIXALGEBRA_H__
#define __MATH_MATRIXALGEBRA_H__

#include <vector>

namespace MathMatrixAlgebra {

std::vector<double> MatrixMultiply(const std::vector<std::vector<double>> &a, const std::vector<double> &x);
std::vector<std::vector<double>> MatrixMultiply(const std::vector<std::vector<double>> &a,
                                                const std::vector<std::vector<double>> &b);
std::vector<std::vector<double>> RotatePoints(const std::vector<std::vector<double>> &points,
                                              const std::vector<std::vector<double>> &rotmat);
std::vector<double> LinearSolver(const std::vector<std::vector<double>> &equations, const std::vector<double> &inputs);
void LuDecompose(const std::vector<std::vector<double>> &A, std::vector<std::vector<double>> &L,
                 std::vector<std::vector<double>> &U);
std::vector<double> ForwardSubstitution(const std::vector<std::vector<double>> &L, const std::vector<double> &b);
std::vector<double> BackwardSubstitution(const std::vector<std::vector<double>> &U, const std::vector<double> &y);

};   // namespace MathMatrixAlgebra

#endif   // !__MATH_MATRIXALGEBRA_H__
