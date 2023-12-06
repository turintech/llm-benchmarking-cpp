#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "control/single.h"
#include "generator/genvector.h"

TEST_CASE("SingleForLoop::SumRange::Test", "[test][control][singlefor]") {
  REQUIRE(SingleForLoop::SumRange(0) == 0);
  REQUIRE(SingleForLoop::SumRange(1) == 0);
  REQUIRE(SingleForLoop::SumRange(2) == 1);
  REQUIRE(SingleForLoop::SumRange(3) == 3);
  REQUIRE(SingleForLoop::SumRange(4) == 6);
  REQUIRE(SingleForLoop::SumRange(10) == 45);
}

TEST_CASE("SingleForLoop::SumRange::Benchmark", "[benchmark][control][singlefor]") {
  BENCHMARK("SumRange(10000)") { return SingleForLoop::SumRange(10000); };
}

TEST_CASE("SingleForLoop::MaxRandom::Test", "[test][control][singlefor]") {
  REQUIRE(SingleForLoop::MaxArray(GenVector::RandomVector(0, 1)) == 0);
  REQUIRE(SingleForLoop::MaxArray(GenVector::RandomVector(100, 10)) <= 10);
}

TEST_CASE("SingleForLoop::MaxRandom::Benchmark", "[benchmark][control][singlefor]") {
  BENCHMARK("MaxArray(RandomVector(10000, 100))") {
    return SingleForLoop::MaxArray(GenVector::RandomVector(10000, 100));
  };
}

TEST_CASE("SingleForLoop::SumModulus::Test", "[test][control][singlefor]") {
  REQUIRE(SingleForLoop::SumModulus(0, 2) == 0);
  REQUIRE(SingleForLoop::SumModulus(1, 2) == 0);
  REQUIRE(SingleForLoop::SumModulus(2, 2) == 0);
  REQUIRE(SingleForLoop::SumModulus(3, 2) == 2);
  REQUIRE(SingleForLoop::SumModulus(4, 2) == 2);
  REQUIRE(SingleForLoop::SumModulus(10, 2) == 20);
  REQUIRE(SingleForLoop::SumModulus(10, 3) == 18);
  REQUIRE(SingleForLoop::SumModulus(10, 4) == 12);
}

TEST_CASE("SingleForLoop::SumModulus::Benchmark", "[benchmark][control][singlefor]") {
  BENCHMARK("SumModulus(10000, 2)") { return SingleForLoop::SumModulus(10000, 2); };
}
