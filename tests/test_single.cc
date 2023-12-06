#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "control/single.h"

TEST_CASE("SingleForLoop::SumRange::Test", "[test][control][singlefor]") {
  SingleForLoop sfl;
  REQUIRE(sfl.SumRange(0) == 0);
  REQUIRE(sfl.SumRange(1) == 0);
  REQUIRE(sfl.SumRange(2) == 1);
  REQUIRE(sfl.SumRange(3) == 3);
  REQUIRE(sfl.SumRange(4) == 6);
  REQUIRE(sfl.SumRange(10) == 45);
}

TEST_CASE("SingleForLoop::SumRange::Benchmark", "[benchmark][control][singlefor]") {
  SingleForLoop sfl;
  BENCHMARK("SumRange(10000)") { return sfl.SumRange(10000); };
}

TEST_CASE("SingleForLoop::MaxRandom::Test", "[test][control][singlefor]") {
  SingleForLoop sfl;
  REQUIRE(sfl.MaxRandom(0) == 0);
  REQUIRE(sfl.MaxRandom(10) > 0);
}

TEST_CASE("SingleForLoop::MaxRandom::Benchmark", "[benchmark][control][singlefor]") {
  SingleForLoop sfl;
  BENCHMARK("MaxRandom(10000)") { return sfl.MaxRandom(10000); };
}

TEST_CASE("SingleForLoop::SumModulus::Test", "[test][control][singlefor]") {
  SingleForLoop sfl;
  REQUIRE(sfl.SumModulus(0, 2) == 0);
  REQUIRE(sfl.SumModulus(1, 2) == 0);
  REQUIRE(sfl.SumModulus(2, 2) == 0);
  REQUIRE(sfl.SumModulus(3, 2) == 2);
  REQUIRE(sfl.SumModulus(4, 2) == 2);
  REQUIRE(sfl.SumModulus(10, 2) == 20);
  REQUIRE(sfl.SumModulus(10, 3) == 18);
  REQUIRE(sfl.SumModulus(10, 4) == 12);
}

TEST_CASE("SingleForLoop::SumModulus::Benchmark", "[benchmark][control][singlefor]") {
  SingleForLoop sfl;
  BENCHMARK("SumModulus(10000, 2)") { return sfl.SumModulus(10000, 2); };
}
