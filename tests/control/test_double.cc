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
  std::vector<int> var0 = {0};
  std::vector<int> var1 = {1, 2, 3};
  std::vector<int> var2 = {1, 1, 1};
  std::vector<int> var3 = {1, 1, 2};
  std::vector<int> var4 = {1, 1, 2, 2};
  std::vector<int> var5 = {0, 0, 1, 1, 2, 2};
  std::vector<int> var6 = {0, 0, 1, 1, 2, 2, 3};

  REQUIRE(DoubleForLoop::CountPairs(var0) == 0);
  REQUIRE(DoubleForLoop::CountPairs(var1) == 0);
  REQUIRE(DoubleForLoop::CountPairs(var2) == 0);
  REQUIRE(DoubleForLoop::CountPairs(var3) == 1);
  REQUIRE(DoubleForLoop::CountPairs(var4) == 2);
  REQUIRE(DoubleForLoop::CountPairs(var5) == 3);
  REQUIRE(DoubleForLoop::CountPairs(var6) == 3);
}

TEST_CASE("DoubleForLoop::CountPairs::Benchmark", "[benchmark][control][doublefor]") {
  BENCHMARK("CountPairs(1000, 100)") { return DoubleForLoop::CountPairs(GenVector::RandomVector(1000, 100)); };
}

TEST_CASE("DoubleForLoop::CountDuplicates::Test", "[test][control][doublefor]") {
  std::vector<int> varL0 = {0};
  std::vector<int> varR0 = {0};
  std::vector<int> varL1 = {1, 2, 3};
  std::vector<int> varR1 = {2, 3, 1};
  std::vector<int> varL2 = {1, 1, 1};
  std::vector<int> varR2 = {1, 2, 3};
  std::vector<int> varL3 = {1, 1, 2};
  std::vector<int> varR3 = {1, 2, 2};
  std::vector<int> varL4 = {1, 1, 2, 2};
  std::vector<int> varR4 = {1, 1, 2, 2};

  REQUIRE(DoubleForLoop::CountDuplicates(varL0, varR0) == 1);
  REQUIRE(DoubleForLoop::CountDuplicates(varL1, varR1) == 0);
  REQUIRE(DoubleForLoop::CountDuplicates(varL2, varR2) == 1);
  REQUIRE(DoubleForLoop::CountDuplicates(varL3, varR3) == 2);
  REQUIRE(DoubleForLoop::CountDuplicates(varL4, varR4) == 4);
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
