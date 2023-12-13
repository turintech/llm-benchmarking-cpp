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

TEST_CASE("Sort::DutchFlagPartition::Benchmark", "[benchmark][algorithms][sort]") {
  std::vector v0 = GenVector::RandomVector(100000, 10);
  BENCHMARK("DutchFlagPartition(100000, 3)") { Sort::DutchFlagPartition(v0, 3); };
  std::vector v1 = GenVector::RandomVector(100000, 100);
  BENCHMARK("DutchFlagPartition(100000, 50)") { Sort::DutchFlagPartition(v1, 50); };
}

TEST_CASE("Sort::MaxN::Test", "[test][algorithms][sort]") {
  std::vector<int> v0 = {1, 3, 2, 5, 4};
  std::vector<int> v0_max3 = Sort::MaxN(v0, 3);
  REQUIRE(v0_max3 == std::vector<int>({5, 4, 3}));
  std::vector<int> v0_max2 = Sort::MaxN(v0, 2);
  REQUIRE(v0_max2 == std::vector<int>({5, 4}));

  std::vector<int> v1 = {1, 1, 2, 2, 3};
  std::vector<int> v1_max3 = Sort::MaxN(v1, 3);
  REQUIRE(v1_max3 == std::vector<int>({3, 2, 2}));
  std::vector<int> v1_max2 = Sort::MaxN(v1, 2);
  REQUIRE(v1_max2 == std::vector<int>({3, 2}));
}

TEST_CASE("Sort::MaxN::Benchmark", "[benchmark][algorithms][sort]") {
  std::vector v0 = GenVector::RandomVector(100000, 10);
  BENCHMARK("MaxN(100000, 10)") { return Sort::MaxN(v0, 10); };
  std::vector v1 = GenVector::RandomVector(100000, 100);
  BENCHMARK("MaxN(100000, 100)") { return Sort::MaxN(v1, 100); };
}
