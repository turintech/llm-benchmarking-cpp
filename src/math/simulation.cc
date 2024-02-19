#include "simulation.h"
#include <cmath>
#include <stdexcept>

const double G = 1;   // Gravitational constant

/** @brief A simple euler gravity simulation for a set of particles in 3d
 *
 * Unrealistic since we don't track velocities and claim that forces directly update positions instead.
 *
 * @param positions, initial particle positions, shape(n, 3)
 * @param dt, the time increment
 * @param iterations, the number of iterations to run for
 *
 * @return finalPositions, the positions after `iterations` iterations of `dt`
 */
std::vector<double>
MathSimulation::PseudoGravity(const std::vector<double> &positions, double dt, int iterations) {
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

/** @brief A simple euler gravity simulation for a set of particles in 3d
 *
 * @param positions, initial particle positions, shape(n, 3)
 * @param velocities, initial particle velocities, shape(n, 3)
 * @param masses, initial particle velocities, shape(n)
 * @param dt, the time increment
 * @param iterations, the number of iterations to run for
 *
 * @return finalPositions, the positions after `iterations` iterations of `dt`
 */
std::vector<double>
MathSimulation::SimpleGravity(const std::vector<double> &positions, const std::vector<double> &velocities,
                              const std::vector<double> &masses, double dt, int iterations) {
  if (positions.size() % 3 != 0) {
    throw std::invalid_argument("Invalid matrix size `positions`, expected a multiple of 3");
  }
  if (velocities.size() % 3 != 0) {
    throw std::invalid_argument("Invalid matrix size `velocities`, expected a multiple of 3");
  }
  if (velocities.size() != positions.size()) {
    throw std::invalid_argument("Invalid matrix size `velocities`, expected to match `positions");
  }
  int n = positions.size() / 3;
  if (masses.size() != n) {
    throw std::invalid_argument("Invalid vector size `masses`");
  }
  std::vector<double> finalPositions(positions);
  std::vector<double> finalVelocities(velocities);

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

    // Update velocities
    for (int i = 0; i < n; ++i) {
      finalVelocities[i * 3 + 0] += dt * forces[i * 3 + 0] / masses[i];
      finalVelocities[i * 3 + 1] += dt * forces[i * 3 + 1] / masses[i];
      finalVelocities[i * 3 + 2] += dt * forces[i * 3 + 2] / masses[i];
    }
    // Update positions
    for (int i = 0; i < n; ++i) {
      finalPositions[i * 3 + 0] += dt * finalVelocities[i * 3 + 0];
      finalPositions[i * 3 + 1] += dt * finalVelocities[i * 3 + 1];
      finalPositions[i * 3 + 2] += dt * finalVelocities[i * 3 + 2];
    }
  }

  return finalPositions;
}

std::vector<int>
MathSimulation::MandelbrotSet(double cx, double cy, double zoom, int width, int height, int iterations) {
  std::vector<int> result(width * height, 0);
  double xs = cx - 0.5 / zoom;
  double ys = cy + 0.5 * height / (zoom * width);
  double inc = 1.0 / (zoom * width);
  for (int j = 0; j < height; j++) {
    double y = ys - inc * j;
    for (int i = 0; i < width; i++) {
      result[j * width + i] = MandelbrotPoint(xs + inc * i, y, iterations);
    }
  }
  return result;
}

int
MathSimulation::MandelbrotPoint(double cx, double cy, int iterations) {
  int count = 0;
  double x = 0;
  double y = 0;
  while (count < iterations && x * x + y * y <= 4.0) {
    double nx = x * x - y * y + cx;
    y = 2.0 * x * y + cy;
    x = nx;
    count++;
  }
  return count;
}
