#ifndef __MATH_MATRIXALGEBRA_H__
#define __MATH_MATRIXALGEBRA_H__

#include <vector>

namespace MathMatrixAlgebra {

std::vector<std::vector<double>> MatrixMultiply(std::vector<std::vector<double>> &a,
                                                std::vector<std::vector<double>> &b);
std::vector<std::vector<double>> RotatePoints(std::vector<std::vector<double>> &points,
                                              std::vector<std::vector<double>> &rotmat);

};   // namespace MathMatrixAlgebra

#endif   // !__MATH_MATRIXALGEBRA_H__
