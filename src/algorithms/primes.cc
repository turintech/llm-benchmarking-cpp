#include "primes.h"

Primes::Primes() {}

bool Primes::IsPrime(int n) {
  // returns true if n is prime, false otherwise
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i < n; i += 1) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int Primes::SumPrimes(int n) {
  // sums all prime numbers from 0 to n
  int sum = 0;

  for (int i = 0; i < n; i += 1) {
    if (IsPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

std::vector<int> Primes::PrimeFactors(int n) {
  // returns a vector of all prime factors of n
  std::vector<int> factors;

  for (int i = 2; i <= n; i += 1) {
    while (IsPrime(i) && n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  return factors;
}
