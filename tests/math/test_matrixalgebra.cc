#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "generator/genvector.h"
#include "math/matrixalgebra.h"
#include "testhelpers/testervector.h"

TEST_CASE("MatrixAlgebra::MatrixMultiply::Test", "[test][math][matrixalgebra]") {
  std::vector<double> x0 = {1, 2, 3};
  std::vector<std::vector<double>> a0 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  std::vector<std::vector<double>> a1 = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
  std::vector<std::vector<double>> a2 = {{1, -1, 1}, {-1, -1, -1}, {1, -1, 1}};
  std::vector<double> y0ref = {1, 2, 3};
  std::vector<double> y1ref = {2, 4, 6};
  std::vector<double> y2ref = {2, -6, 2};
  std::vector<std::vector<double>> z0ref = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
  std::vector<std::vector<double>> z1ref = {{4, 0, 0}, {0, 4, 0}, {0, 0, 4}};
  std::vector<std::vector<double>> z2ref = {{3, -1, 3}, {-1, 3, -1}, {3, -1, 3}};

  SECTION("a0@x0") {
    std::vector<double> y0 = MathMatrixAlgebra::MatrixMultiply(a0, x0);
    TestHelpers::check_vectors_equal(y0ref, y0);
  }
  SECTION("a1@x0") {
    std::vector<double> y1 = MathMatrixAlgebra::MatrixMultiply(a1, x0);
    TestHelpers::check_vectors_equal(y1ref, y1);
  }
  SECTION("a2@x0") {
    std::vector<double> y2 = MathMatrixAlgebra::MatrixMultiply(a2, x0);
    TestHelpers::check_vectors_equal(y2ref, y2);
  }
  SECTION("a0@a1") {
    std::vector<std::vector<double>> z0 = MathMatrixAlgebra::MatrixMultiply(a0, a1);
    TestHelpers::check_matrices_equal(z0ref, z0);
  }
  SECTION("a1@a1") {
    std::vector<std::vector<double>> z1 = MathMatrixAlgebra::MatrixMultiply(a1, a1);
    TestHelpers::check_matrices_equal(z1ref, z1);
  }
  SECTION("a2@a2") {
    std::vector<std::vector<double>> z2 = MathMatrixAlgebra::MatrixMultiply(a2, a2);
    TestHelpers::check_matrices_equal(z2ref, z2);
  }
}

TEST_CASE("MatrixAlgebra::MatrixMultiply::Benchmark", "[benchmark][math][matrixalgebra]") {
  std::vector<std::vector<double>> a0 = GenVector::RandomSquareMatrixDouble(100, 0, 1);
  std::vector<double> x0 = GenVector::RandomVectorDouble(100, 0, 1);
  BENCHMARK("MatrixMultiply((100, 100), (100))") { return MathMatrixAlgebra::MatrixMultiply(a0, x0); };
  std::vector<std::vector<double>> a1 = GenVector::RandomMatrixDouble(1000, 100, 0, 1);
  std::vector<double> x1 = GenVector::RandomVectorDouble(100, 0, 1);
  BENCHMARK("MatrixMultiply((1000, 100), (100))") { return MathMatrixAlgebra::MatrixMultiply(a1, x1); };
  std::vector<std::vector<double>> a2 = GenVector::RandomMatrixDouble(100, 1000, 0, 1);
  std::vector<double> x2 = GenVector::RandomVectorDouble(1000, 0, 1);
  BENCHMARK("MatrixMultiply((100, 1000), (1000))") { return MathMatrixAlgebra::MatrixMultiply(a2, x2); };
  BENCHMARK("MatrixMultiply((100, 1000), (1000))") { return MathMatrixAlgebra::MatrixMultiply(a0, a0); };
  BENCHMARK("MatrixMultiply((100, 1000), (1000))") { return MathMatrixAlgebra::MatrixMultiply(a2, a1); };
}

TEST_CASE("MatrixAlgebra::RotatePoints::Test", "[test][math][matrixalgebra]") {
  std::vector<std::vector<double>> points2d = {{1, 0}, {2, 0}, {3, 3}, {-2, 4}};
  std::vector<std::vector<double>> points3d = {{1, 0, 0}, {0, 2, 0}, {3, 3, 2}, {-2, 4, 4}, {1, -4, -1}};
  std::vector<std::vector<double>> rotmat2d90d = {{0, -1}, {1, 0}};
  std::vector<std::vector<double>> rotmat2d30d = {{0.866, -0.5}, {0.5, 0.866}};
  std::vector<std::vector<double>> rotmat3d90dy = {{0, 0, -1}, {0, 1, 0}, {1, 0, 0}};
  std::vector<std::vector<double>> rotmat3d30dy30dz = {{0.75, -0.5, 0.433}, {0.433, 0.866, 0.25}, {-0.5, 0, 0.866}};

  std::vector<std::vector<double>> p0ref = {{0, 1}, {0, 2}, {-3, 3}, {-4, -2}};
  std::vector<std::vector<double>> p1ref = {{0.866, 0.5}, {1.732, 1}, {1.098, 4.098}, {-3.732, 2.464}};
  std::vector<std::vector<double>> p2ref = {{0, 0, 1}, {0, 2, 0}, {-2, 3, 3}, {-4, 4, -2}, {1, -4, 1}};
  std::vector<std::vector<double>> p3ref = {
      {0.75, 0.433, -0.5}, {-1, 1.732, 0}, {1.616, 4.397, 0.232}, {-1.768, 3.598, 4.464}, {2.317, -3.281, -1.366}};

  SECTION("2d rotation 90 degrees") {
    std::vector<std::vector<double>> p0 = MathMatrixAlgebra::RotatePoints(points2d, rotmat2d90d);
    TestHelpers::check_matrices_almost_equal(p0ref, p0);
  }
  SECTION("2d rotation 30 degrees") {
    std::vector<std::vector<double>> p1 = MathMatrixAlgebra::RotatePoints(points2d, rotmat2d30d);
    TestHelpers::check_matrices_almost_equal(p1ref, p1);
  }
  SECTION("3d rotation 90 degrees y") {
    std::vector<std::vector<double>> p2 = MathMatrixAlgebra::RotatePoints(points3d, rotmat3d90dy);
    TestHelpers::check_matrices_almost_equal(p2ref, p2);
  }
  SECTION("3d rotation 30 degrees y 30 degrees z") {
    std::vector<std::vector<double>> p3 = MathMatrixAlgebra::RotatePoints(points3d, rotmat3d30dy30dz);
    TestHelpers::check_matrices_almost_equal(p3ref, p3);
  }
}

TEST_CASE("MatrixAlgebra::RotatePoints::Benchmark", "[benchmark][math][matrixalgebra]") {
  std::vector<std::vector<double>> a2 = GenVector::RandomSquareMatrixDouble(2, -1, 1);
  std::vector<std::vector<double>> a3 = GenVector::RandomSquareMatrixDouble(3, -1, 1);
  std::vector<std::vector<double>> a8 = GenVector::RandomSquareMatrixDouble(8, -1, 1);
  std::vector<std::vector<double>> points2 = GenVector::RandomMatrixDouble(10000, 2, -1, 1);
  std::vector<std::vector<double>> points3 = GenVector::RandomMatrixDouble(10000, 3, -1, 1);
  std::vector<std::vector<double>> points8 = GenVector::RandomMatrixDouble(10000, 8, -1, 1);
  BENCHMARK("RotatePoints(2, 10000)") { return MathMatrixAlgebra::RotatePoints(points2, a2); };
  BENCHMARK("RotatePoints(3, 10000)") { return MathMatrixAlgebra::RotatePoints(points3, a3); };
  BENCHMARK("RotatePoints(8, 10000)") { return MathMatrixAlgebra::RotatePoints(points8, a8); };
}

TEST_CASE("MatrixAlgebra::LinearSolver::Test", "[test][math][matrixalgebra]") {
  std::vector<std::vector<double>> a0 = {{1, 2}, {3, 5}};
  std::vector<double> v0 = {1, 2};
  std::vector<double> x0ref = {-1, 1};
  std::vector<std::vector<double>> a1 = {{1, 2, -1}, {-3, -1, 2}, {-2, 1, 2}};
  std::vector<double> v1 = {8, -11, -3};
  std::vector<double> x1ref = {2.8, 2.6, 0};
  SECTION("2d") {
    std::vector<double> x0 = MathMatrixAlgebra::LinearSolver(a0, v0);
    TestHelpers::check_vectors_almost_equal(x0ref, x0);
  }
  SECTION("3d") {
    std::vector<double> x1 = MathMatrixAlgebra::LinearSolver(a1, v1);
    TestHelpers::check_vectors_almost_equal(x1ref, x1);
  }
}

TEST_CASE("MatrixAlgebra::LuDecomposition::Test", "[test][math][matrixalgebra]") {
  std::vector<std::vector<double>> A = {{4, 3}, {6, 3}};
  std::vector<std::vector<double>> L;
  std::vector<std::vector<double>> U;
  std::vector<std::vector<double>> Lref = {{1, 0}, {1.5, 1}};
  std::vector<std::vector<double>> Uref = {{4, 3}, {0, -1.5}};
  MathMatrixAlgebra::LuDecompose(A, L, U);
  TestHelpers::check_matrices_almost_equal(Lref, L);
  TestHelpers::check_matrices_almost_equal(Uref, U);
  SECTION("Backwards check") {
    std::vector<std::vector<double>> Aback = MathMatrixAlgebra::MatrixMultiply(L, U);
    TestHelpers::check_matrices_almost_equal(A, Aback);
  }
}

TEST_CASE("MatrixAlgebra::ForwardSubstitution::Test", "[test][math][matrixalgebra]") {
  std::vector<std::vector<double>> L0 = {{2, 0, 0}, {-1, 1, 0}, {2, -1, 1}};
  std::vector<double> v0 = {2, 1, 3};
  std::vector<double> y0ref = {1, 2, 3};
  std::vector<double> y0 = MathMatrixAlgebra::ForwardSubstitution(L0, v0);
  TestHelpers::check_vectors_almost_equal(y0ref, y0);
  SECTION("Backwards check") {
    std::vector<double> v0back = MathMatrixAlgebra::MatrixMultiply(L0, y0);
    TestHelpers::check_vectors_almost_equal(v0, v0back);
  }
}

TEST_CASE("MatrixAlgebra::BackwardSubstitution::Test", "[test][math][matrixalgebra]") {
  std::vector<std::vector<double>> U0 = {{2, -1, 0}, {0, 1, -1}, {0, 0, 3}};
  std::vector<double> y0 = {1, 2, -9};
  std::vector<double> x0ref = {0, -1, -3};
  std::vector<double> x0 = MathMatrixAlgebra::BackwardSubstitution(U0, y0);
  TestHelpers::check_vectors_almost_equal(x0ref, x0);
  SECTION("Backwards check") {
    std::vector<double> y0back = MathMatrixAlgebra::MatrixMultiply(U0, x0);
    TestHelpers::check_vectors_almost_equal(y0, y0back);
  }
}
