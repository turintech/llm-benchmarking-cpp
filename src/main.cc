#include <iostream>

#include "algorithms/primes.h"
#include "control/double.h"
#include "control/single.h"
#include "datastructures/vector.h"
#include "strings/generator.h"
#include "strings/palindrome.h"
#include "strings/reverse.h"

void _single() {
  std::cout << "SingleForLoop" << std::endl;
  std::cout << "-------------" << std::endl;

  SingleForLoop single;
  int n = 1000000;
  std::cout << "SumRange(" << n << "): " << single.SumRange(n) << std::endl;
  std::cout << "MaxRandom(" << n << "): " << single.MaxRandom(n) << std::endl;
  std::cout << "SumModulus(" << n << ", 2): " << single.SumModulus(n, 2)
            << std::endl;

  std::cout << std::endl;
}

void _double() {
  std::cout << "DoubleForLoop" << std::endl;
  std::cout << "-------------" << std::endl;

  DoubleForLoop double_;
  int n = 10000;
  std::cout << "SumSquare(" << n << "): " << double_.SumSquare(n) << std::endl;
  std::cout << "Triangle(" << n << "): " << double_.SumTriangle(n) << std::endl;
  std::cout << "CountPairs(" << n << "): " << double_.CountPairs(n)
            << std::endl;
  std::cout << "CountDuplicates(" << n << "): " << double_.CountDuplicates(n)
            << std::endl;

  std::cout << std::endl;
}

void _palindrome() {
  std::cout << "Palindrome" << std::endl;
  std::cout << "----------" << std::endl;

  Generator generator;
  Palindrome palindrome;
  std::string randS = generator.RandomString(1000000);
  std::string s = "racecar";
  std::cout << "IsPalindrome(" << s << "): " << palindrome.IsPalindrome(s)
            << std::endl;
  std::cout << "IsPalindrome(RandomString(1000000)): "
            << palindrome.IsPalindrome(randS) << std::endl;

  std::cout << std::endl;
}

void _reverse() {
  std::cout << "Reverse" << std::endl;
  std::cout << "-------" << std::endl;

  Generator generator;
  Reverse reverse;
  std::string randS = generator.RandomString(1000000);
  std::string s = "hello world";
  std::cout << "Reverse(" << s << "): " << reverse.ReverseString(s)
            << std::endl;
  // Printing this is too long
  reverse.ReverseString(randS);

  std::cout << std::endl;
}

void _primes() {
  std::cout << "Primes" << std::endl;
  std::cout << "------" << std::endl;

  Primes primes;
  int n = 100000;
  std::cout << "SumPrimes(" << n << "): " << primes.SumPrimes(n) << std::endl;
  n = 1248264;
  std::vector<int> factors = primes.PrimeFactors(n);
  std::cout << "PrimeFactors(" << n << "): ";
  for (int i = 0; i < (int)factors.size(); i += 1) {
    std::cout << factors[i] << " ";
  }
  std::cout << std::endl;

  std::cout << std::endl;
}

void _vector() {
  std::cout << "Vector" << std::endl;
  std::cout << "------" << std::endl;

  Vector vector;
  std::vector<int> v1 = vector.RandomVector(20);
  std::vector<int> v2 = vector.RandomVector(20);
  std::cout << "RandomVector(20): ";
  for (int i = 0; i < (int)v1.size(); i += 1) {
    std::cout << v1[i] << " ";
  }
  std::vector<int> vModified = vector.ModifyVector(v1);
  std::vector<int> vSorted = vector.SortVector(v1);
  std::vector<int> vSearched = vector.SearchVector(v1, 27);
  std::vector<int> vReversed = vector.ReverseVector(v1);
  std::vector<int> vRotated = vector.RotateVector(v1, 5);
  std::vector<int> vMerged = vector.MergeVectors(v1, v2);
  std::cout << std::endl;
  std::cout << "ModifyVector(RandomVector(20)): ";
  for (int i = 0; i < (int)vModified.size(); i += 1) {
    std::cout << vModified[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "SortVector(RandomVector(20)): ";
  for (int i = 0; i < (int)vSorted.size(); i += 1) {
    std::cout << vSorted[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "SearchVector(RandomVector(20), 27): ";
  for (int i = 0; i < (int)vSearched.size(); i += 1) {
    std::cout << vSearched[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "ReverseVector(RandomVector(20)): ";
  for (int i = 0; i < (int)vReversed.size(); i += 1) {
    std::cout << vReversed[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "RotateVector(RandomVector(20), 5): ";
  for (int i = 0; i < (int)vRotated.size(); i += 1) {
    std::cout << vRotated[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "MergeVectors(RandomVector(20), RandomVector(20)): ";
  for (int i = 0; i < (int)vMerged.size(); i += 1) {
    std::cout << vMerged[i] << " ";
  }
  std::cout << std::endl;

  std::cout << std::endl;
}

int main(int argc, char **argv) {
  _single();
  _double();
  _palindrome();
  _reverse();
  _primes();
  _vector();
  return 0;
}
