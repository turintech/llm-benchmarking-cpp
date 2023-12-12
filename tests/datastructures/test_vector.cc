#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "datastructures/vector.h"
#include "generator/genvector.h"

TEST_CASE("Vector::ModifyVector::Test", "[test][datastructures][vector]") {
  std::vector<int> v = {1, 2, 3, 4, 5};
  REQUIRE(OpsVector::ModifyVector(v).size() == v.size());
  for (int i = 0; i < v.size(); i++) {
    REQUIRE(OpsVector::ModifyVector(v).at(i) == v.at(i) + 1);
  }

  std::vector v0 = {0};
  std::vector v0ref = {1};
  std::vector v1 = {1, 2, 3};
  std::vector v1ref = {2, 3, 4};
  std::vector v2 = {1, 1, 1};
  std::vector v2ref = {2, 2, 2};
  std::vector v3 = {1, 1, 2};
  std::vector v3ref = {2, 2, 3};

  REQUIRE(OpsVector::ModifyVector(v0) == v0ref);
  REQUIRE(OpsVector::ModifyVector(v1) == v1ref);
  REQUIRE(OpsVector::ModifyVector(v2) == v2ref);
  REQUIRE(OpsVector::ModifyVector(v3) == v3ref);
}

TEST_CASE("Vector::ModifyVector::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  BENCHMARK("ModifyVector(1000)") { return OpsVector::ModifyVector(v0); };
  std::vector<int> v1 = GenVector::RandomVector(10000, 100);
  BENCHMARK("ModifyVector(10000)") { return OpsVector::ModifyVector(v1); };
}

TEST_CASE("Vector::SortVector::Test", "[test][datastructures][vector]") {
  std::vector<int> v0 = {5, 4, 3, 2, 1};
  std::vector<int> v0sorted = {1, 2, 3, 4, 5};
  REQUIRE(OpsVector::SortVector(v0).size() == v0.size());
  REQUIRE(OpsVector::SortVector(v0) == v0sorted);
  std::vector<int> v1 = {3, 3, 2, 2, 4, 3, 0, 5};
  std::vector<int> v1sorted = {0, 2, 2, 3, 3, 3, 4, 5};
  REQUIRE(OpsVector::SortVector(v1) == v1sorted);
}

TEST_CASE("Vector::SortVector::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  BENCHMARK("SortVector(1000)") { return OpsVector::SortVector(v0); };
  std::vector<int> v1 = GenVector::RandomVector(10000, 100);
  BENCHMARK("SortVector(10000)") { return OpsVector::SortVector(v1); };
}

TEST_CASE("Vector::SearchVector::Test", "[test][datastructures][vector]") {
  std::vector<int> v = {1, 2, 3, 4, 5};
  REQUIRE(OpsVector::SearchVector(v, 1).size() == 1);
  REQUIRE(OpsVector::SearchVector(v, 1).at(0) == 0);
  REQUIRE(OpsVector::SearchVector(v, 2).size() == 1);
  REQUIRE(OpsVector::SearchVector(v, 2).at(0) == 1);
  REQUIRE(OpsVector::SearchVector(v, 9).size() == 0);
}

TEST_CASE("Vector::SearchVector::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  BENCHMARK("SearchVector(1000, exists)") { return OpsVector::SearchVector(v0, 0); };
  std::vector<int> v1 = GenVector::RandomVector(10000, 100);
  BENCHMARK("SearchVector(10000, exists)") { return OpsVector::SearchVector(v1, 3); };
  std::vector<int> v2 = GenVector::RandomVector(1000, 3);
  BENCHMARK("SearchVector(10, not exists)") { return OpsVector::SearchVector(v2, 7); };
  std::vector<int> v3 = GenVector::RandomVector(10000, 100);
  BENCHMARK("SearchVector(104, not exists)") { return OpsVector::SearchVector(v3, 104); };
}

TEST_CASE("Vector::ReverseVector::Test", "[test][datastructures][vector]") {
  std::vector<int> v0 = {1, 2, 3, 4, 5};
  std::vector<int> v0rev = {5, 4, 3, 2, 1};
  std::vector<int> v1 = {1, 3, 2, 0};
  std::vector<int> v1rev = {0, 2, 3, 1};
  std::vector<int> v2 = {1, 1, 1, 1, 1};
  REQUIRE(OpsVector::ReverseVector(v0).size() == v0.size());
  REQUIRE(OpsVector::ReverseVector(v0) == v0rev);
  REQUIRE(OpsVector::ReverseVector(v1) == v1rev);
  REQUIRE(OpsVector::ReverseVector(v2) == v2);
}

TEST_CASE("Vector::ReverseVector::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  BENCHMARK("ReverseVector(1000)") { return OpsVector::ReverseVector(v0); };
  std::vector<int> v1 = GenVector::RandomVector(10000, 100);
  BENCHMARK("ReverseVector(10000)") { return OpsVector::ReverseVector(v1); };
}

TEST_CASE("Vector::RotateVector::Test", "[test][datastructures][vector]") {
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::vector<int> vrot2 = {3, 4, 5, 1, 2};
  std::vector<int> vrot5 = {1, 2, 3, 4, 5};
  REQUIRE(OpsVector::RotateVector(v, 2) == vrot2);
  REQUIRE(OpsVector::RotateVector(v, 5) == vrot5);
}

TEST_CASE("Vector::RotateVector::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  BENCHMARK("RotateVector(1000)") { return OpsVector::RotateVector(v0, 5); };
  std::vector<int> v1 = GenVector::RandomVector(10000, 100);
  BENCHMARK("RotateVector(10000)") { return OpsVector::RotateVector(v1, 5); };
}

TEST_CASE("Vector::MergeVectors::Test", "[test][datastructures][vector]") {
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  std::vector<int> v2 = {6, 7, 8, 9, 10};
  std::vector<int> vMerged = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  REQUIRE(OpsVector::MergeVectors(v1, v2) == vMerged);
}

TEST_CASE("Vector::MergeVectors::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  std::vector<int> v1 = GenVector::RandomVector(1000, 100);
  BENCHMARK("MergeVectors(1000)") { return OpsVector::MergeVectors(v0, v1); };
  std::vector<int> v2 = GenVector::RandomVector(10000, 100);
  std::vector<int> v3 = GenVector::RandomVector(10000, 100);
  BENCHMARK("MergeVectors(10000)") { return OpsVector::MergeVectors(v2, v3); };
}
