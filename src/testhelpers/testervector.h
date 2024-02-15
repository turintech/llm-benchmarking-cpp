#ifndef TESTHELPERS_TESTERVECTOR_H_
#define TESTHELPERS_TESTERVECTOR_H_

#include <cstddef>
#include <cstdlib>
#include <vector>

namespace TestHelpers {

template <typename T>
void
check_vectors_equal(const std::vector<T> &v1, const std::vector<T> &v2) {
  INFO("Comparing vector length: Expected " << v1.size() << ", got " << v2.size());
  REQUIRE(v1.size() == v2.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    INFO("Comparing element at index " << i << ": Expected " << v1[i] << ", got " << v2[i]);
    REQUIRE(v1[i] == v2[i]);
  }
}

template <typename T>
void
check_vectors_almost_equal(const std::vector<T> &v1, const std::vector<T> &v2, double absdiff = 0.02) {
  INFO("Comparing vector length: Expected " << v1.size() << ", got " << v2.size());
  REQUIRE(v1.size() == v2.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    INFO("Comparing element at index " << i << ": Expected " << v1[i] << ", got " << v2[i]);
    REQUIRE(std::abs(v1[i] - v2[i]) < absdiff);
  }
}

template <typename T>
void
check_matrices_equal(const std::vector<std::vector<T>> &a1, const std::vector<std::vector<T>> &a2) {
  INFO("Comparing matrix shape: Expected (" << a1.size() << ", " << a1[0].size() << ")"
                                            << ", got (" << a2.size() << ", " << a2[0].size() << ")");
  REQUIRE(a1.size() == a2.size());
  REQUIRE(a1[0].size() == a2[0].size());

  for (size_t i = 0; i < a1.size(); ++i) {
    for (size_t j = 0; j < a1[0].size(); ++j) {
      INFO("Comparing element at index (" << i << ", " << j << "): Expected " << a1[i][j] << ", got " << a2[i][j]);
      REQUIRE(a1[i][j] == a2[i][j]);
    }
  }
}

template <typename T>
void
check_matrices_almost_equal(const std::vector<std::vector<T>> &a1, const std::vector<std::vector<T>> &a2,
                            double absdiff = 0.02) {
  INFO("Comparing matrix shape: Expected (" << a1.size() << ", " << a1[0].size() << ")"
                                            << ", got (" << a2.size() << ", " << a2[0].size() << ")");
  REQUIRE(a1.size() == a2.size());
  REQUIRE(a1[0].size() == a2[0].size());

  for (size_t i = 0; i < a1.size(); ++i) {
    for (size_t j = 0; j < a1[0].size(); ++j) {
      INFO("Comparing element at index (" << i << ", " << j << "): Expected " << a1[i][j] << ", got " << a2[i][j]);
      REQUIRE(std::abs(a1[i][j] - a2[i][j]) < absdiff);
    }
  }
}
}   // namespace TestHelpers

#endif   // !TESTHELPERS_TESTERVECTOR_H_
