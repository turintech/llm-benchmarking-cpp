#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "generator/genvector.h"
#include "math/simulation.h"
#include "testhelpers/testervector.h"

TEST_CASE("Simulation::PseudoGravity::Test", "[test][math][simulation]") {
  SECTION("2d setup") {
    std::vector<double> x = {0, 0, 2, 0, 0, -2};
    std::vector<double> yref = {0, 0, 1.938, 0, 0, -1.938};
    std::vector<double> y = MathSimulation::PseudoGravity(x, 1, 1);
    TestHelpers::check_vectors_almost_equal(yref, y);
  }
  SECTION("3d setup") {
    std::vector<double> x = {0, 1, 2, -1, 0, 4, 2, 0, 0};
    std::vector<double> yref = {-0.001, 1, 2.091, -0.887, 0, 3.789, 1.888, 0, 0.120};
    std::vector<double> y = MathSimulation::PseudoGravity(x, 1, 1);
    TestHelpers::check_vectors_almost_equal(yref, y);
  }
}

TEST_CASE("Simulation::PseudoGravity::Benchmark", "[benchmark][math][simulation]") {
  std::vector<double> x0 = GenVector::RandomVectorDouble(3000, -1, 1);
  BENCHMARK("SimpleGravity((1000), 0.1, 100)") { return MathSimulation::PseudoGravity(x0, 0.1, 100); };
  std::vector<double> x1 = GenVector::RandomVectorDouble(300, -1, 1);
  BENCHMARK("SimpleGravity((100), 0.1, 1000)") { return MathSimulation::PseudoGravity(x1, 0.1, 1000); };
  std::vector<double> x2 = GenVector::RandomVectorDouble(30, -1, 1);
  BENCHMARK("SimpleGravity((10), 0.1, 10000)") { return MathSimulation::PseudoGravity(x2, 0.1, 10000); };
}

TEST_CASE("Simulation::BetterGravity::Test", "[test][math][simulation]") {
  std::vector<double> x0 = {0, 1, 2, -1, 0, 4, 2, 0, 0};
  std::vector<double> v0 = {-1, 0, 0, 0, 3, 2, 0, -1, 0};
  std::vector<double> m0 = {1, 1, 0.6};
  std::vector<double> yref0 = {-0.1, 1, 2, -1, 0.3, 4.198, 1.999, -0.1, 0};
  std::vector<double> y0 = MathSimulation::SimpleGravity(x0, v0, m0, 0.1, 1);
  TestHelpers::check_vectors_almost_equal(yref0, y0);
}

TEST_CASE("Simulation::SimpleGravity::Benchmark", "[benchmark][math][simulation]") {
  std::vector<double> x0 = GenVector::RandomVectorDouble(3000, -1, 1);
  std::vector<double> v0 = GenVector::RandomVectorDouble(3000, -1, 1);
  std::vector<double> m0 = GenVector::RandomVectorDouble(1000, -1, 1);
  BENCHMARK("SimpleGravity((1000), 0.1, 100)") { return MathSimulation::SimpleGravity(x0, v0, m0, 1, 100); };
  std::vector<double> x1 = GenVector::RandomVectorDouble(300, -1, 1);
  std::vector<double> v1 = GenVector::RandomVectorDouble(300, -1, 1);
  std::vector<double> m1 = GenVector::RandomVectorDouble(100, -1, 1);
  BENCHMARK("SimpleGravity((100), 0.1, 1000)") { return MathSimulation::SimpleGravity(x1, v1, m1, 1, 1000); };
  std::vector<double> x2 = GenVector::RandomVectorDouble(30, -1, 1);
  std::vector<double> v2 = GenVector::RandomVectorDouble(30, -1, 1);
  std::vector<double> m2 = GenVector::RandomVectorDouble(10, -1, 1);
  BENCHMARK("SimpleGravity((10), 0.1, 10000)") { return MathSimulation::SimpleGravity(x2, v2, m2, 1, 10000); };
}

TEST_CASE("Simulation::MandelbrotPoint::Test", "[test][math][simulation]") {
  SECTION("(0, 0)") {
    double x = 0;
    double y = 0;
    int iter = 50000;
    int ref = 50000;
    int c = MathSimulation::MandelbrotPoint(x, y, iter);
    REQUIRE(ref == c);
  }
  SECTION("(-0.57, 0.57)") {
    double x = -0.57;
    double y = 0.57;
    int iter = 50000;
    int ref = 79;
    int c = MathSimulation::MandelbrotPoint(x, y, iter);
    REQUIRE(ref == c);
  }
}

TEST_CASE("Simulation::MandelbrotSet::Test", "[test][math][simulation]") {
  SECTION("(0, 0)") {
    double x = 0;
    double y = 0;
    int width = 3;
    int height = 3;
    std::vector<int> ref(9, 50000);
    std::vector<int> grid = MathSimulation::MandelbrotSet(x, y, 1.0, width, height, 50000);
    TestHelpers::check_vectors_equal(ref, grid);
  }
  SECTION("(-0.57, 0.57)") {
    double x = -0.57;
    double y = 0.57;
    int width = 3;
    int height = 3;
    std::vector<int> ref = {66, 52, 26, 22, 30, 38, 26, 28, 70};
    std::vector<int> grid = MathSimulation::MandelbrotSet(x, y, 100.0, width, height, 50000);
    TestHelpers::check_vectors_equal(ref, grid);
  }
}

TEST_CASE("Simulation::MandelbrotSet::Benchmark", "[benchmark][math][simulation]") {
  BENCHMARK("MandelbrotSet(slow(20, 20), 50000)") {
    return MathSimulation::MandelbrotSet(0, 0, 1000.0, 20, 20, 50000);
  };
  BENCHMARK("MandelbrotSet(fast(1000, 1000), 50000)") {
    return MathSimulation::MandelbrotSet(-0.57, 0.57, 1000.0, 1000, 1000, 50000);
  };
}
