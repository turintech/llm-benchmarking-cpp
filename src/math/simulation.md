## Simple Gravity

This should be a simple demo of an LLMs ability to apply some kind of GPU accelerated library to code.

### GPT-4 Working Recommendation

```cpp
using namespace sycl;
std::vector<double>
MathSimulation::SimpleGravity(const std::vector<double> &positions, double dt, int iterations) {
  if (positions.size() % 3 != 0) {
    throw std::invalid_argument("Invalid matrix size `positions`, expected a multiple of 3");
  }
  int n = positions.size() / 3;
  std::vector<double> finalPositions(positions);
  std::vector<double> initForces(3 * n, 0.0);

  // SYCL buffers for positions and forces
  queue q(default_selector_v);
  buffer<double, 1> positionsBuffer(positions.data(), range<1>(3 * n));
  buffer<double, 1> forcesBuffer(initForces.data(), range<1>(3 * n));

  for (int iter = 0; iter < iterations; ++iter) {
    // Reset forces to zero at the start of each iteration
    q.submit([&](handler &h) {
      auto forces = forcesBuffer.get_access<access::mode::write>(h);
      h.parallel_for<class resetForcesKernel>(range<1>(3 * n), [=](id<1> i) { forces[i] = 0.0; });
    });

    // Compute forces
    q.submit([&](handler &h) {
      auto pos = positionsBuffer.get_access<access::mode::read>(h);
      auto forces = forcesBuffer.get_access<access::mode::read_write>(h);
      h.parallel_for<class NBodyKernel>(range<1>(n * (n - 1) / 2), [=](id<1> idx) {
        int i = idx / n;
        int j = idx % n;
        if (i < j) {
          double dx = pos[j * 3 + 0] - pos[i * 3 + 0];
          double dy = pos[j * 3 + 1] - pos[i * 3 + 1];
          double dz = pos[j * 3 + 2] - pos[i * 3 + 2];
          double dist = sqrt(dx * dx + dy * dy + dz * dz) + 1e-10;   // Avoid division by zero
          double forceMagnitude = G / (dist * dist);
          double fx = forceMagnitude * dx / dist;
          double fy = forceMagnitude * dy / dist;
          double fz = forceMagnitude * dz / dist;
          forces[i * 3 + 0] += fx;
          forces[i * 3 + 1] += fy;
          forces[i * 3 + 2] += fz;
          forces[j * 3 + 0] -= fx;
          forces[j * 3 + 1] -= fy;
          forces[j * 3 + 2] -= fz;
        }
      });
    });

    // Update positions
    q.submit([&](handler &h) {
      auto pos = positionsBuffer.get_access<access::mode::read_write>(h);
      auto forces = forcesBuffer.get_access<access::mode::read>(h);
      h.parallel_for<class updatePositionsKernel>(range<1>(n), [=](id<1> i) {
        pos[i * 3 + 0] += dt * forces[i * 3 + 0];
        pos[i * 3 + 1] += dt * forces[i * 3 + 1];
        pos[i * 3 + 2] += dt * forces[i * 3 + 2];
      });
    });
  }

  q.wait_and_throw();

  // Copy back to positions vector
  auto finalPositions = positionsBuffer.get_access<access::mode::read>();
  return finalPositions;
}
```
