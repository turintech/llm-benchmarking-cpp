#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "control/double.h"
#include "control/single.h"

TEST_CASE("SingleForLoop::SumRange", "[control]") {
  SingleForLoop sfl;
  REQUIRE(sfl.SumRange(0) == 0);
  REQUIRE(sfl.SumRange(1) == 0);
  REQUIRE(sfl.SumRange(2) == 1);
  REQUIRE(sfl.SumRange(3) == 3);
  REQUIRE(sfl.SumRange(4) == 6);
  REQUIRE(sfl.SumRange(10) == 45);

  BENCHMARK("SumRange(10000)") { return sfl.SumRange(10000); };
}

TEST_CASE("SingleForLoop::MaxRandom", "[control]") {
  SingleForLoop sfl;
  REQUIRE(sfl.MaxRandom(0) == 0);
  REQUIRE(sfl.MaxRandom(10) > 0);

  BENCHMARK("MaxRandom(10000)") { return sfl.MaxRandom(10000); };
}
