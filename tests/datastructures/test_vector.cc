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
  REQUIRE(OpsVector::SortVector(v1).size() == v1.size());
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
  std::vector<int> v = {1, 2, 3, 4, 5};
  REQUIRE(OpsVector::ReverseVector(v).size() == v.size());
  REQUIRE(OpsVector::ReverseVector(v).at(0) == 5);
  REQUIRE(OpsVector::ReverseVector(v).at(1) == 4);
  REQUIRE(OpsVector::ReverseVector(v).at(2) == 3);
  REQUIRE(OpsVector::ReverseVector(v).at(3) == 2);
  REQUIRE(OpsVector::ReverseVector(v).at(4) == 1);
}

TEST_CASE("Vector::ReverseVector::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  BENCHMARK("ReverseVector(1000)") { return OpsVector::ReverseVector(v0); };
  std::vector<int> v1 = GenVector::RandomVector(10000, 100);
  BENCHMARK("ReverseVector(10000)") { return OpsVector::ReverseVector(v1); };
}

TEST_CASE("Vector::RotateVector::Test", "[test][datastructures][vector]") {
  std::vector<int> v = {1, 2, 3, 4, 5};
  REQUIRE(OpsVector::RotateVector(v, 2).size() == v.size());
  REQUIRE(OpsVector::RotateVector(v, 2).at(0) == 3);
  REQUIRE(OpsVector::RotateVector(v, 2).at(1) == 4);
  REQUIRE(OpsVector::RotateVector(v, 2).at(2) == 5);
  REQUIRE(OpsVector::RotateVector(v, 2).at(3) == 1);
  REQUIRE(OpsVector::RotateVector(v, 2).at(4) == 2);
  REQUIRE(OpsVector::RotateVector(v, 5).size() == v.size());
  REQUIRE(OpsVector::RotateVector(v, 5).at(0) == 1);
  REQUIRE(OpsVector::RotateVector(v, 5).at(1) == 2);
  REQUIRE(OpsVector::RotateVector(v, 5).at(2) == 3);
  REQUIRE(OpsVector::RotateVector(v, 5).at(3) == 4);
  REQUIRE(OpsVector::RotateVector(v, 5).at(4) == 5);
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
  REQUIRE(OpsVector::MergeVectors(v1, v2).size() == v1.size() + v2.size());
  REQUIRE(OpsVector::MergeVectors(v1, v2).at(0) == 1);
  REQUIRE(OpsVector::MergeVectors(v1, v2).at(1) == 2);
  REQUIRE(OpsVector::MergeVectors(v1, v2).at(5) == 6);
  REQUIRE(OpsVector::MergeVectors(v1, v2).at(9) == 10);
}

TEST_CASE("Vector::MergeVectors::Benchmark", "[benchmark][datastructures][vector]") {
  std::vector<int> v0 = GenVector::RandomVector(1000, 100);
  std::vector<int> v1 = GenVector::RandomVector(1000, 100);
  BENCHMARK("MergeVectors(1000)") { return OpsVector::MergeVectors(v0, v1); };
  std::vector<int> v2 = GenVector::RandomVector(10000, 100);
  std::vector<int> v3 = GenVector::RandomVector(10000, 100);
  BENCHMARK("MergeVectors(10000)") { return OpsVector::MergeVectors(v2, v3); };
}
