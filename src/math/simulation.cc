#include "simulation.h"
#include <cmath>
#include <stdexcept>

const double G = 6.67430e-11;   // Gravitational constant

/** @brief A simple euler gravity simulation for a set of particles in 3d
 *
 * @param positions, initial particle positions, shape(n, 3)
 * @param dt, the time increment
 * @param iterations, the number of iterations to run for
 *
 * @return finalPositions, the positions after `iterations` iterations of `dt`
 */
std::vector<double>
MathSimulation::SimpleGravity(const std::vector<double> &positions, double dt, int iterations) {
  if (positions.size() % 3 != 0) {
    throw std::invalid_argument("Invalid matrix size `positions`, expected a multiple of 3");
  }
  int n = positions.size() / 3;
  std::vector<double> finalPositions(positions);

  for (int it = 0; it < iterations; it++) {
    std::vector<double> forces(n * 3, 0.0);
    // Compute forces
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        double dx = finalPositions[j * 3 + 0] - finalPositions[i * 3 + 0];
        double dy = finalPositions[j * 3 + 1] - finalPositions[j * 3 + 1];
        double dz = finalPositions[j * 3 + 2] - finalPositions[i * 3 + 2];
        double dist = sqrt(dx * dx + dy * dy + dz * dz);
        double forceMagnitude = G / (dist * dist + 1e-10);   // Adding a small term to prevent division by zero

        forces[i * 3 + 0] += forceMagnitude * dx / dist;
        forces[i * 3 + 1] += forceMagnitude * dy / dist;
        forces[i * 3 + 2] += forceMagnitude * dz / dist;
        forces[j * 3 + 0] -= forceMagnitude * dx / dist;
        forces[j * 3 + 1] -= forceMagnitude * dy / dist;
        forces[j * 3 + 2] -= forceMagnitude * dz / dist;
      }
    }

    // Update positions
    for (int i = 0; i < n; ++i) {
      finalPositions[i * 3 + 0] += dt * forces[i * 3 + 0];
      finalPositions[i * 3 + 1] += dt * forces[i * 3 + 1];
      finalPositions[i * 3 + 2] += dt * forces[i * 3 + 2];
    }
  }

  return finalPositions;
}
