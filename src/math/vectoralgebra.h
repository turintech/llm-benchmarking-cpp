#ifndef __MATH_VECTORALGEBRA_H__
#define __MATH_VECTORALGEBRA_H__

#include <vector>

namespace MathVectorAlgebra {

std::vector<double> Cubic(int a, int b, int c, int d, std::vector<double> &x);
std::vector<double> Convolve(int offset, std::vector<double> &h, std::vector<double> &x);

};   // namespace MathVectorAlgebra

#endif   // !__MATH_VECTORALGEBRA_H__
