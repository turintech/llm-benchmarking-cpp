#ifndef __MATH_SIMULATION_H__
#define __MATH_SIMULATION_H__

#include <vector>

// Convenience includes for artemis
#if __has_include(<CL/sycl.hpp>)
#include <CL/sycl.hpp>
#endif   // __has_include

namespace MathSimulation {

std::vector<double> SimpleGravity(const std::vector<double> &positions, double dt, int iterations);

};   // namespace MathSimulation

#endif   // !__MATH_SIMULATION_H__
