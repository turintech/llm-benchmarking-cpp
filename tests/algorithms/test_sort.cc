#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "algorithms/sort.h"
#include "generator/genvector.h"

TEST_CASE("Sort::SortVector::Test", "[test][algorithms][sort]") {
  std::vector<int> v0 = {1, 3, 2, 5, 4};
  Sort::SortVector(v0);
  REQUIRE(v0 == std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> v1 = {-1, 3, 2, 5, 4};
  Sort::SortVector(v1);
  REQUIRE(v1 == std::vector<int>({-1, 2, 3, 4, 5}));

  std::vector<int> v2 = {2, 2, 1, 1, 3};
  Sort::SortVector(v2);
  REQUIRE(v2 == std::vector<int>({1, 1, 2, 2, 3}));
}

TEST_CASE("Sort::SortVector::Benchmark", "[benchmark][algorithms][sort]") {
  std::vector v0 = GenVector::RandomVector(100000, 10);
  BENCHMARK("SortVector(100000, 10)") { Sort::SortVector(v0); };
  std::vector v1 = GenVector::RandomVector(100000, 100);
  BENCHMARK("SortVector(100000, 100)") { Sort::SortVector(v1); };
}

TEST_CASE("Sort::DutchFlagPartition::Test", "[test][algorithms][sort]") {
  std::vector<int> v0 = {1, 3, 2, 5, 4};
  Sort::DutchFlagPartition(v0, 3);
  REQUIRE(v0.at(2) == 3);

  std::vector<int> v1 = {5, 4, 3, 2, 1};
  Sort::DutchFlagPartition(v1, 2);
  REQUIRE(v1.at(1) == 2);

  std::vector<int> v2 = {2, 2, 1, 1, 3};
  std::vector<int> vref = v2;
  Sort::DutchFlagPartition(v2, 4);
  REQUIRE(v2 == vref);
}
