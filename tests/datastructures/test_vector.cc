#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "datastructures/vector.h"
#include "generator/genvector.h"

TEST_CASE("Vector::ModifyVector::Test", "[test][datastructures][vector]") {
  std::vector<int> v = GenVector::RandomVector(1000000, 100);
  REQUIRE(OpsVector::ModifyVector(v).size() == v.size());
  REQUIRE(OpsVector::ModifyVector(v).at(0) == v.at(0) + 1);
}
