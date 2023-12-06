#ifndef ALGORITHMS_PRIMES_H_
#define ALGORITHMS_PRIMES_H_

#include <vector>

class Primes {
public:
  Primes();
  int SumPrimes(int n);
  std::vector<int> PrimeFactors(int n);

private:
  bool IsPrime(int n);
};

#endif   // ALGORITHMS_PRIMES_H_
