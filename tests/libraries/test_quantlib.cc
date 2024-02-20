#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "libraries/quantlib.h"

using namespace QuantLib;

TEST_CASE("Quantlib::PriceOption::Test", "[test][libraries][quantlib]") {
  Real npv0 = LibQuantLib::PriceOption(100.0, 100.0, 0.05, 0.2, Date(20, September, 2024));
}

TEST_CASE("Quantlib::PriceOption::Benchmark", "[benchmark][libraries][quantlib]") {
  BENCHMARK("PriceOption") { return LibQuantLib::PriceOption(100.0, 100.0, 0.05, 0.05, Date(20, March, 2024)); };
}

TEST_CASE("Quantlib::FixedRateBond::Test", "[test][libraries][quantlib]") {
  Real npv0 = LibQuantLib::FixedRateBond(1000.0, 0.05, Date(1, January, 2022), Date(1, January, 2032), Semiannual,
                                         ActualActual(ActualActual::ISMA));
}

TEST_CASE("Quantlib::FixedRateBond::Benchmark", "[benchmark][libraries][quantlib]") {
  BENCHMARK("FixedRateBond") {
    LibQuantLib::FixedRateBond(1000.0, 0.05, Date(1, January, 2022), Date(1, January, 2027), Semiannual,
                               ActualActual(ActualActual::ISMA));
  };
}
