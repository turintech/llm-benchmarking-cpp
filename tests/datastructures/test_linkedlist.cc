#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "datastructures/linkedlist.h"

TEST_CASE("LinkedList::SearchList::Test", "[test][datastructures][linkedlist]") {
  LinkedList l(0);
  REQUIRE(l.SearchList(0));
  REQUIRE(!l.SearchList(1));
}

TEST_CASE("LinkedList::SearchList::Benchmark", "[benchmark][datastructures][linkedlist]") {
  LinkedList l0 = *LinkedList::RandomLinkedList(1000, 10);
  BENCHMARK("SearchList(1000, exists)") { return l0.SearchList(0); };
  LinkedList l1 = *LinkedList::RandomLinkedList(10000, 10);
  BENCHMARK("SearchList(10000, exists)") { return l1.SearchList(3); };
  LinkedList l2 = *LinkedList::RandomLinkedList(1000, 3);
  BENCHMARK("SearchList(10, not exists)") { return l2.SearchList(7); };
  LinkedList l3 = *LinkedList::RandomLinkedList(10000, 10);
  BENCHMARK("SearchList(104, not exists)") { return l3.SearchList(104); };
}

TEST_CASE("LinkedList::At::Test", "[test][datastructures][linkedlist]") {
  LinkedList l(0);
  REQUIRE(l.At(0) == 0);
}

TEST_CASE("LinkedList::At::Benchmark", "[benchmark][datastructures][linkedlist]") {
  LinkedList l0 = *LinkedList::RandomLinkedList(1000, 10);
  BENCHMARK("At(400) (l=1000)") { return l0.At(399); };
  BENCHMARK("At(1000) (l=1000)") { return l0.At(999); };
  LinkedList l1 = *LinkedList::RandomLinkedList(10000, 10);
  BENCHMARK("At(400) (l=10000)") { return l1.At(399); };
  BENCHMARK("At(10000) (l=10000)") { return l1.At(9999); };
}

TEST_CASE("LinkedList::ReverseList::Test", "[test][datastructures][linkedlist]") {
  LinkedList l(0);
  l.AddNode(1);
  l.AddNode(2);
  l.AddNode(3);
  l.AddNode(4);
  l.AddNode(5);
  l.ReverseList();

  REQUIRE(l.At(0) == 5);
  REQUIRE(l.At(1) == 4);
  REQUIRE(l.At(2) == 3);
  REQUIRE(l.At(3) == 2);
  REQUIRE(l.At(4) == 1);
}

TEST_CASE("LinkedList::ReverseList::Benchmark", "[benchmark][datastructures][linkedlist]") {
  LinkedList l0 = *LinkedList::RandomLinkedList(1000, 10);
  BENCHMARK("ReverseList(1000)") { l0.ReverseList(); };
  LinkedList l1 = *LinkedList::RandomLinkedList(10000, 10);
  BENCHMARK("ReverseList(10000)") { l1.ReverseList(); };
}

TEST_CASE("LinkedList::AddNode::Test", "[test][datastructures][linkedlist]") {
  LinkedList l(0);
  l.AddNode(1);
  l.AddNode(2);
  l.AddNode(3);
  l.AddNode(4);
  l.AddNode(5);

  REQUIRE(l.SearchList(0));
  REQUIRE(l.SearchList(1));
  REQUIRE(l.SearchList(2));
  REQUIRE(l.SearchList(3));
  REQUIRE(l.SearchList(4));
  REQUIRE(l.SearchList(5));
  REQUIRE(!l.SearchList(6));

  REQUIRE(l.At(0) == 0);
  REQUIRE(l.At(1) == 1);
  REQUIRE(l.At(2) == 2);
  REQUIRE(l.At(3) == 3);
  REQUIRE(l.At(4) == 4);
  REQUIRE(l.At(5) == 5);
}

TEST_CASE("LinkedList::AddNode::Benchmark", "[benchmark][datastructures][linkedlist]") {
  LinkedList l0 = *LinkedList::RandomLinkedList(1000, 10);
  BENCHMARK("AddNode(1000)") { l0.AddNode(1000); };
  LinkedList l1 = *LinkedList::RandomLinkedList(10000, 10);
  BENCHMARK("AddNode(10000)") { l1.AddNode(10000); };
}
