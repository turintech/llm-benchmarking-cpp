#ifndef __MATH_SIMULATION_H__
#define __MATH_SIMULATION_H__

#include <vector>

// Convenience includes for artemis
#if __has_include(<CL/sycl.hpp>)
#include <CL/sycl.hpp>
#endif   // __has_include

namespace MathSimulation {

std::vector<double> PseudoGravity(const std::vector<double> &positions, double dt, int iterations);
std::vector<double> SimpleGravity(const std::vector<double> &positions, const std::vector<double> &velocities,
                                  const std::vector<double> &masses, double dt, int iterations);
std::vector<int> MandelbrotSet(double cx, double cy, double zoom, int width, int height, int iterations);
int MandelbrotPoint(double cx, double cy, int iterations);

};   // namespace MathSimulation

#endif   // !__MATH_SIMULATION_H__
