#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include "algorithms/primes.h"

TEST_CASE("Primes::IsPrime::Test", "[test][algorithms][primes]") {
  REQUIRE(Primes::IsPrime(0) == false);
  REQUIRE(Primes::IsPrime(1) == false);
  REQUIRE(Primes::IsPrime(2) == true);
  REQUIRE(Primes::IsPrime(3) == true);
  REQUIRE(Primes::IsPrime(4) == false);
  REQUIRE(Primes::IsPrime(10) == false);
  REQUIRE(Primes::IsPrime(17) == true);
  REQUIRE(Primes::IsPrime(26) == false);
}

TEST_CASE("Primes::IsPrime::Benchmark", "[benchmark][algorithms][primes]") {
  BENCHMARK("IsPrime(20000)") { return Primes::IsPrime(20000); };
  BENCHMARK("IsPrime(23641)") { return Primes::IsPrime(23641); };
}

TEST_CASE("Primes::SumPrimes::Test", "[test][algorithms][primes]") {
  REQUIRE(Primes::SumPrimes(0) == 0);
  REQUIRE(Primes::SumPrimes(1) == 0);
  REQUIRE(Primes::SumPrimes(2) == 0);
  REQUIRE(Primes::SumPrimes(3) == 2);
  REQUIRE(Primes::SumPrimes(4) == 5);
  REQUIRE(Primes::SumPrimes(10) == 17);
  REQUIRE(Primes::SumPrimes(100) == 1060);
}

TEST_CASE("Primes::SumPrimes::Benchmark", "[benchmark][algorithms][primes]") {
  BENCHMARK("SumPrimes(10000)") { return Primes::SumPrimes(10000); };
}

TEST_CASE("Primes::PrimeFactors::Test", "[test][algorithms][primes]") {
  REQUIRE(Primes::PrimeFactors(0) == std::vector<int>());
  REQUIRE(Primes::PrimeFactors(1) == std::vector<int>());
  REQUIRE(Primes::PrimeFactors(2) == std::vector<int>({2}));
  REQUIRE(Primes::PrimeFactors(3) == std::vector<int>({3}));
  REQUIRE(Primes::PrimeFactors(4) == std::vector<int>({2, 2}));
  REQUIRE(Primes::PrimeFactors(10) == std::vector<int>({2, 5}));
  REQUIRE(Primes::PrimeFactors(17) == std::vector<int>({17}));
  REQUIRE(Primes::PrimeFactors(84) == std::vector<int>({2, 2, 3, 7}));
}

TEST_CASE("Primes::PrimeFactors::Benchmark", "[benchmark][algorithms][primes]") {
  BENCHMARK("PrimeFactors(1248264)") { return Primes::PrimeFactors(1248264); };
  BENCHMARK("PrimeFactors(6475108)") { return Primes::PrimeFactors(64750); };
  BENCHMARK("PrimeFactors(23641)") { return Primes::PrimeFactors(23641); };
}
