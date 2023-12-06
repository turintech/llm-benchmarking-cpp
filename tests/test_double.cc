#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "control/double.h"
#include "generator/genvector.h"

TEST_CASE("DoubleForLoop::SumSquare::Test", "[test][control][doublefor]") {
  REQUIRE(DoubleForLoop::SumSquare(1) == 0);
  REQUIRE(DoubleForLoop::SumSquare(2) == 1);
  REQUIRE(DoubleForLoop::SumSquare(3) == 5);
  REQUIRE(DoubleForLoop::SumSquare(10) == 285);
}

TEST_CASE("DoubleForLoop::SumSquare::Benchmark", "[benchmark][control][doublefor]") {
  BENCHMARK("SumSquare(1000)") { return DoubleForLoop::SumSquare(1000); };
}

TEST_CASE("DoubleForLoop::SumTriangle::Test", "[test][control][doublefor]") {
  REQUIRE(DoubleForLoop::SumTriangle(1) == 0);
  REQUIRE(DoubleForLoop::SumTriangle(2) == 1);
  REQUIRE(DoubleForLoop::SumTriangle(3) == 4);
  REQUIRE(DoubleForLoop::SumTriangle(10) == 165);
}

TEST_CASE("DoubleForLoop::SumTriangle::Benchmark", "[benchmark][control][doublefor]") {
  BENCHMARK("SumTriangle(1000)") { return DoubleForLoop::SumTriangle(1000); };
}

TEST_CASE("DoubleForLoop::CountPairs::Test", "[test][control][doublefor]") {
  // For each case, we generate a random array of size `n` with values between
  // 0 and `m`. We then count the number of pairs in the array.
  //
  // When `m` is 1, the result is deterministic. There are no pairs unless
  // `n` is 2, for which there must be one pair.
  // When `m` > 1, the result is non-deterministic. We can assert that the
  // maximum number of pairs is equal to `m`
  REQUIRE(DoubleForLoop::CountPairs(GenVector::RandomVector(0, 1)) == 0);
  REQUIRE(DoubleForLoop::CountPairs(GenVector::RandomVector(1, 1)) == 0);
  REQUIRE(DoubleForLoop::CountPairs(GenVector::RandomVector(2, 1)) == 1);
  REQUIRE(DoubleForLoop::CountPairs(GenVector::RandomVector(10, 1)) == 0);
  REQUIRE(DoubleForLoop::CountPairs(GenVector::RandomVector(10, 2)) <= 2);
  REQUIRE(DoubleForLoop::CountPairs(GenVector::RandomVector(10, 4)) <= 4);

  std::vector<int> var0 = {0, 0, 1, 1, 2, 2};
  REQUIRE(DoubleForLoop::CountPairs(var0) == 3);

  std::vector<int> var1 = {0, 0, 1, 1, 2, 2, 3};
  REQUIRE(DoubleForLoop::CountPairs(var1) == 3);
}

TEST_CASE("DoubleForLoop::CountPairs::Benchmark", "[benchmark][control][doublefor]") {
  BENCHMARK("CountPairs(1000, 100)") { return DoubleForLoop::CountPairs(GenVector::RandomVector(1000, 100)); };
}

TEST_CASE("DoubleForLoop::CountDuplicates::Test", "[test][control][doublefor]") {
  // For each case, we generate a random array of size `n` with values between
  // 0 and `m`. We then count the number of pairs in the array.
  //
  // When `m` is 1, the result is deterministic. There can only be duplicates.
  // When `m` > 1, the result is non-deterministic. We can assert that the max
  // number of duplicates is equal to `n`.
  REQUIRE(DoubleForLoop::CountDuplicates(GenVector::RandomVector(0, 1), GenVector::RandomVector(0, 1)) == 0);
  REQUIRE(DoubleForLoop::CountDuplicates(GenVector::RandomVector(1, 1), GenVector::RandomVector(1, 1)) == 1);
  REQUIRE(DoubleForLoop::CountDuplicates(GenVector::RandomVector(2, 1), GenVector::RandomVector(2, 1)) == 2);
  REQUIRE(DoubleForLoop::CountDuplicates(GenVector::RandomVector(10, 1), GenVector::RandomVector(10, 1)) == 10);
  REQUIRE(DoubleForLoop::CountDuplicates(GenVector::RandomVector(10, 2), GenVector::RandomVector(10, 2)) <= 10);
  REQUIRE(DoubleForLoop::CountDuplicates(GenVector::RandomVector(10, 4), GenVector::RandomVector(10, 4)) <= 10);

  std::vector<int> var0 = {0, 1, 2, 3, 4};
  std::vector<int> var1 = {0, 2, 3, 3, 4};
  std::vector<int> var2 = {0, 1, 3, 3, 5};

  REQUIRE(DoubleForLoop::CountDuplicates(var0, var1) == 3);
  REQUIRE(DoubleForLoop::CountDuplicates(var0, var2) == 3);
  REQUIRE(DoubleForLoop::CountDuplicates(var1, var2) == 3);
}

TEST_CASE("DoubleForLoop::CountDuplicates::Benchmark", "[benchmark][control][doublefor]") {
  BENCHMARK("CountDuplicates(1000, 100)") {
    return DoubleForLoop::CountDuplicates(GenVector::RandomVector(1000, 100), GenVector::RandomVector(1000, 100));
  };
}

TEST_CASE("DoubleForLoop::SumMatrix::Test", "[test][control][doublefor]") {
  std::vector<std::vector<int>> matrix0 = {{0}};
  REQUIRE(DoubleForLoop::SumMatrix(matrix0) == 0);

  std::vector<std::vector<int>> matrix1 = {{0, 1}, {2, 3}};
  REQUIRE(DoubleForLoop::SumMatrix(matrix1) == 6);

  std::vector<std::vector<int>> matrix2 = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  REQUIRE(DoubleForLoop::SumMatrix(matrix2) == 36);
}
