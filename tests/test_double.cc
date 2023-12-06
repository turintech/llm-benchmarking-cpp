#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "control/double.h"

TEST_CASE("DoubleForLoop::SumSquare::Test", "[test][control][doublefor]") {
  DoubleForLoop double_;
  REQUIRE(double_.SumSquare(1) == 0);
  REQUIRE(double_.SumSquare(2) == 1);
  REQUIRE(double_.SumSquare(3) == 5);
  REQUIRE(double_.SumSquare(10) == 285);
}

TEST_CASE("DoubleForLoop::SumSquare::Benchmark", "[benchmark][control][doublefor]") {
  DoubleForLoop double_;
  BENCHMARK("SumSquare(1000)") { return double_.SumSquare(1000); };
}

TEST_CASE("DoubleForLoop::SumTriangle::Test", "[test][control][doublefor]") {
  DoubleForLoop double_;
  REQUIRE(double_.SumTriangle(1) == 0);
  REQUIRE(double_.SumTriangle(2) == 1);
  REQUIRE(double_.SumTriangle(3) == 4);
  REQUIRE(double_.SumTriangle(10) == 165);
}

TEST_CASE("DoubleForLoop::SumTriangle::Benchmark", "[benchmark][control][doublefor]") {
  DoubleForLoop double_;
  BENCHMARK("SumTriangle(1000)") { return double_.SumTriangle(1000); };
}

TEST_CASE("DoubleForLoop::CountPairs::Test", "[test][control][doublefor]") {
  DoubleForLoop double_;
  // When `m` is 1, the result is deterministic. There are no pairs unless
  // `n` is 2, for which there must be one pair.
  // When `m` > 1, the result is non-deterministic. We can assert that the
  // maximum number of pairs is equal to `m`
  REQUIRE(double_.CountPairs(0, 1) == 0);
  REQUIRE(double_.CountPairs(1, 1) == 0);
  REQUIRE(double_.CountPairs(2, 1) == 1);
  REQUIRE(double_.CountPairs(10, 1) == 0);
  REQUIRE(double_.CountPairs(10, 2) <= 2);
  REQUIRE(double_.CountPairs(10, 4) <= 4);
}

TEST_CASE("DoubleForLoop::CountPairs::Benchmark", "[benchmark][control][doublefor]") {
  DoubleForLoop double_;
  BENCHMARK("CountPairs(1000, 100)") { return double_.CountPairs(1000, 100); };
}

TEST_CASE("DoubleForLoop::CountDuplicates::Test", "[test][control][doublefor]") {
  DoubleForLoop double_;
  // When `m` is 1, the result is deterministic. There can only be duplicates.
  // When `m` > 1, the result is non-deterministic. We can assert that the max
  // number of duplicates is equal to `n`.
  REQUIRE(double_.CountDuplicates(0, 1) == 0);
  REQUIRE(double_.CountDuplicates(1, 1) == 1);
  REQUIRE(double_.CountDuplicates(2, 1) == 2);
  REQUIRE(double_.CountDuplicates(10, 1) == 10);
  REQUIRE(double_.CountDuplicates(10, 2) < 10);
  REQUIRE(double_.CountDuplicates(10, 4) < 10);
}

TEST_CASE("DoubleForLoop::CountDuplicates::Benchmark", "[benchmark][control][doublefor]") {
  DoubleForLoop double_;
  BENCHMARK("CountDuplicates(1000, 100)") { return double_.CountDuplicates(1000, 100); };
}

TEST_CASE("DoubleForLoop::SumMatrix::Test", "[test][control][doublefor]") {
  DoubleForLoop double_;
  REQUIRE(double_.SumMatrix(0) == 0);
  REQUIRE(double_.SumMatrix(1) >= 0);
  REQUIRE(double_.SumMatrix(2) >= 0);
  REQUIRE(double_.SumMatrix(3) >= 0);
}
