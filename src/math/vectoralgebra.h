#ifndef __MATH_VECTORALGEBRA_H__
#define __MATH_VECTORALGEBRA_H__

#include <vector>

// Convenience includes for artemis
#if __has_include(<CL/sycl.hpp>)
#include <CL/sycl.hpp>
#endif   // __has_include

namespace MathVectorAlgebra {

std::vector<double> Cubic(int a, int b, int c, int d, const std::vector<double> &x);
std::vector<double> Convolve(int offset, const std::vector<double> &h, const std::vector<double> &x);

};   // namespace MathVectorAlgebra

#endif   // !__MATH_VECTORALGEBRA_H__
