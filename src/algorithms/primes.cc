#include "primes.h"

/** @brief Checks if a number is prime
 *
 *  @param n Number to check
 *  @return True if n is prime, false otherwise
 */
bool Primes::IsPrime(int n) {
  if (n <= 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

/** @brief Sums all prime numbers from 0 to n
 *
 *  @param n Upper bound (non-inclusive) of the sum
 *  @return The sum of all prime numbers from 0 to n
 */
int
Primes::SumPrimes(int n) {
  int sum = 0;

  for (int i = 0; i < n; i += 1) {
    if (IsPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

/** @brief Finds all prime factors of a number
 *
 *  @param n Number to find prime factors of
 *  @return A vector of all prime factors of n
 */
std::vector<int>
Primes::PrimeFactors(int n) {
  std::vector<int> factors;

  for (int i = 2; i <= n; i += 1) {
    while (IsPrime(i) && n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  return factors;
}