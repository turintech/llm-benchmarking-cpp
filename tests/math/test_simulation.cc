#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "generator/genvector.h"
#include "math/simulation.h"
#include "testhelpers/testervector.h"

TEST_CASE("Simulation::SimpleGravity::Test", "[test][math][simulation]") {
  std::vector<double> x0 = {0, 10, 20, -10, 0, 40, 20, 0, 0};
  std::vector<double> yref0 = {0, 10, 20, -10, 0, 40, 20, 0, 0};
  std::vector<double> y0 = MathSimulation::SimpleGravity(x0, 0.1, 1);
  TestHelpers::check_vectors_almost_equal(yref0, y0);
}

TEST_CASE("Simulation::SimpleGravity::Benchmark", "[benchmark][math][simulation]") {
  std::vector<double> x0 = GenVector::RandomVectorDouble(3000, -100, 100);
  BENCHMARK("SimpleGravity((1000), 0.1, 100)") { return MathSimulation::SimpleGravity(x0, 0.1, 100); };
  std::vector<double> x1 = GenVector::RandomVectorDouble(300, -100, 100);
  BENCHMARK("SimpleGravity((100), 0.1, 1000)") { return MathSimulation::SimpleGravity(x1, 0.1, 1000); };
  std::vector<double> x2 = GenVector::RandomVectorDouble(30, -100, 100);
  BENCHMARK("SimpleGravity((10), 0.1, 10000)") { return MathSimulation::SimpleGravity(x2, 0.1, 10000); };
}
