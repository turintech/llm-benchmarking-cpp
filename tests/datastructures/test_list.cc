#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <list>

#include "datastructures/list.h"
#include "generator/genlist.h"

TEST_CASE("List::Shuffle::Test", "[test][datastructures][list]") {
  std::list l = {1, 2, 3, 4, 5};

  std::list shuffled = OpsList::Shuffle(l);
  REQUIRE(shuffled.size() == l.size());
  REQUIRE(shuffled != l);
  shuffled.sort();
  REQUIRE(shuffled == l);
}

TEST_CASE("List::Shuffle::Benchmark", "[benchmark][datastructures][list]") {
  std::list l0 = GenList::RandomList(1000, 100);
  BENCHMARK("Shuffle(1000)") { return OpsList::Shuffle(l0); };
  std::list l1 = GenList::RandomList(10000, 100);
  BENCHMARK("Shuffle(10000)") { return OpsList::Shuffle(l1); };
}

TEST_CASE("List::Slice::Test", "[test][datastructures][list]") {
  std::list l = {1, 2, 3, 4, 5};

  std::list sliced = OpsList::Slice(l, 1, 4);
  REQUIRE(sliced.size() == 3);
  REQUIRE(sliced.front() == 2);
  REQUIRE(sliced.back() == 4);
}

TEST_CASE("List::Slice::Benchmark", "[benchmark][datastructures][list]") {
  std::list l0 = GenList::RandomList(1000, 100);
  BENCHMARK("Slice(1000, 50)") { return OpsList::Slice(l0, 400, 450); };
  BENCHMARK("Slice(1000, 500)") { return OpsList::Slice(l0, 400, 900); };
}
