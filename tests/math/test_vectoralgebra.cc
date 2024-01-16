#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "generator/genvector.h"
#include "math/vectoralgebra.h"

TEST_CASE("VectorAlgebra::Cubic::Test", "[test][math][vectoralgebra]") {
  std::vector<double> x0 = {1, 2, 3, 4, 5};
  std::vector<double> x1 = {0, 1, 2, 3, 4, 10};
  std::vector<double> y0 = MathVectorAlgebra::Cubic(1, -1, -2, 4, x0);
  std::vector<double> y1 = MathVectorAlgebra::Cubic(1, 0, 0, 10, x1);
  std::vector<double> y2 = MathVectorAlgebra::Cubic(0, 5, -3, -4, x1);
  std::vector<double> y3 = MathVectorAlgebra::Cubic(1, 3, -4, 4, x1);
  std::vector<double> y0ref = {2, 4, 16, 44, 94};
  std::vector<double> y1ref = {10, 11, 18, 37, 74, 1010};
  std::vector<double> y2ref = {-4, -2, 10, 32, 64, 466};
  for (int i = 0; i < 5; i++) {
    REQUIRE(y0[i] == y0ref[i]);
  }
  for (int i = 0; i < 5; i++) {
    REQUIRE(y1[i] == y1ref[i]);
  }
  for (int i = 0; i < 5; i++) {
    REQUIRE(y2[i] == y2ref[i]);
  }
  for (int i = 0; i < 5; i++) {
    REQUIRE(y3[i] != y2ref[i]);
  }
}

TEST_CASE("VectorAlgebra::Cubic::Benchmark", "[benchmark][math][vectoralgebra]") {
  std::vector<double> x0 = GenVector::RandomVectorDouble(1000, -10, 10);
  BENCHMARK("Cubic(1000)") { return MathVectorAlgebra::Cubic(1, -1, -2, 4, x0); };
  std::vector<double> x1 = GenVector::RandomVectorDouble(10000, -10, 10);
  BENCHMARK("Cubic(10000)") { return MathVectorAlgebra::Cubic(-2, 1, 3, -8, x1); };
  std::vector<double> x2 = GenVector::RandomVectorDouble(100000, -10, 10);
  BENCHMARK("Cubic(10000)") { return MathVectorAlgebra::Cubic(3, -1, 1, 3, x2); };
}

TEST_CASE("VectorAlgebra::Convolve::Test", "[test][math][vectoralgebra]") {
  std::vector<double> x0 = {1, 2, 3, 4, 5};
  std::vector<double> h0 = {-1, 5, -1};
  std::vector<double> h1 = {-1, 4, -1};

  std::vector<double> y0 = MathVectorAlgebra::Convolve(1, h0, x0);
  std::vector<double> y1 = MathVectorAlgebra::Convolve(1, h1, x0);
  std::vector<double> y0ref = {0.428, 0.857, 1.286, 1.714, 3.000};
  std::vector<double> y1ref = {0.333, 0.667, 1.000, 1.333, 2.667};
  for (int i = 0; i < 5; i++) {
    REQUIRE(std::abs(y0[i] - y0ref[i]) < 0.002);
  }
  for (int i = 0; i < 5; i++) {
    REQUIRE(std::abs(y1[i] - y1ref[i]) < 0.002);
  }
}

TEST_CASE("VectorAlgebra::Convolve::Benchmark", "[benchmark][math][vectoralgebra]") {
  std::vector<double> x0 = GenVector::RandomVectorDouble(1000, -10, 10);
  std::vector<double> h0 = GenVector::RandomVectorDouble(3, -1, 1);
  BENCHMARK("Convolve(1000, 3)") { return MathVectorAlgebra::Convolve(1, h0, x0); };
  std::vector<double> x1 = GenVector::RandomVectorDouble(10000, -10, 10);
  std::vector<double> h1 = GenVector::RandomVectorDouble(3, -1, 1);
  BENCHMARK("Convolve(10000, 3)") { return MathVectorAlgebra::Convolve(1, h1, x1); };
  std::vector<double> x2 = GenVector::RandomVectorDouble(10000, -10, 10);
  std::vector<double> h2 = GenVector::RandomVectorDouble(15, -1, 1);
  BENCHMARK("Convolve(10000, 15)") { return MathVectorAlgebra::Convolve(7, h2, x2); };
}