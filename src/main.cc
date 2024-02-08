#include <iostream>

#include "algorithms/primes.h"
#include "algorithms/sort.h"
#include "control/double.h"
#include "control/single.h"
#include "datastructures/linkedlist.h"
#include "datastructures/vector.h"
#include "generator/genarray.h"
#include "generator/genstring.h"
#include "generator/genvector.h"
#include "math/vectoralgebra.h"
#include "strings/strops.h"

void
_single() {
  std::cout << "Single For Loop" << std::endl;
  std::cout << "---------------" << std::endl;

  int n = 1000000;
  std::vector<int> arr = GenVector::RandomVector(n, 100);
  std::cout << "SumRange(" << n << "): " << SingleForLoop::SumRange(n) << std::endl;
  std::cout << "MaxVector(Random" << n << "): " << SingleForLoop::MaxVector(arr) << std::endl;
  std::cout << "SumModulus(" << n << ", 2): " << SingleForLoop::SumModulus(n, 2) << std::endl;

  std::cout << std::endl;
}

void
_double() {
  std::cout << "Double For Loop" << std::endl;
  std::cout << "---------------" << std::endl;

  int n = 10000;
  std::vector<int> arr0 = GenVector::RandomVector(n, 1000);
  std::vector<int> arr1 = GenVector::RandomVector(n, 100);
  std::vector<int> arr2 = GenVector::RandomVector(n, 100);
  std::cout << "SumSquare(" << n << "): " << DoubleForLoop::SumSquare(n) << std::endl;
  std::cout << "Triangle(" << n << "): " << DoubleForLoop::SumTriangle(n) << std::endl;
  std::cout << "CountPairs(" << n << "): " << DoubleForLoop::CountPairs(arr0) << std::endl;
  std::cout << "CountDuplicates(" << n << "): " << DoubleForLoop::CountDuplicates(arr1, arr2) << std::endl;

  std::cout << std::endl;
}

void
_strops() {
  std::cout << "String Operations" << std::endl;
  std::cout << "-----------------" << std::endl;

  std::string randS = GenString::RandomString(1000000);
  std::string s0 = "racecar";
  std::cout << "IsPalindrome(" << s0 << "): " << StrOps::IsPalindrome(s0) << std::endl;
  std::cout << "IsPalindrome(RandomString(1000000)): " << StrOps::IsPalindrome(randS) << std::endl;
  std::string s1 = "hello world";
  std::cout << "Reverse(" << s1 << "): " << StrOps::ReverseString(s1) << std::endl;
  // Printing this is too long
  StrOps::ReverseString(randS);

  std::cout << std::endl;
}

void
_primes() {
  std::cout << "Primes" << std::endl;
  std::cout << "------" << std::endl;

  int n = 10000;
  std::cout << "SumPrimes(" << n << "): " << Primes::SumPrimes(n) << std::endl;
  n = 1248264;
  std::vector<int> factors = Primes::PrimeFactors(n);
  std::cout << "PrimeFactors(" << n << "): ";
  for (int i = 0; i < (int) factors.size(); i += 1) {
    std::cout << factors[i] << " ";
  }
  std::cout << std::endl;

  std::cout << std::endl;
}

void
_sort() {
  std::cout << "Sort" << std::endl;
  std::cout << "----" << std::endl;

  std::vector<int> v0 = GenVector::RandomVector(20, 10);
  std::cout << "RandomVector(20): ";
  OpsVector::PrintVector(v0);
  std::cout << "SortVector(RandomVector(20)): ";
  Sort::SortVector(v0);
  OpsVector::PrintVector(v0);
  std::vector<int> v1 = GenVector::RandomVector(20, 10);
  std::cout << "RandomVector(20): ";
  OpsVector::PrintVector(v1);
  std::cout << "DutchFlagPartition(RandomVector(20, 5)): ";
  Sort::DutchFlagPartition(v1, 5);
  OpsVector::PrintVector(v1);
  std::vector<int> v2 = GenVector::RandomVector(20, 10);
  std::cout << "RandomVector(20): ";
  OpsVector::PrintVector(v2);
  std::cout << "MaxN(20, 5): ";
  std::vector<int> vMaxN = Sort::MaxN(v2, 5);
  OpsVector::PrintVector(vMaxN);

  std::cout << std::endl;
}

void
_vector() {
  std::cout << "Vector" << std::endl;
  std::cout << "------" << std::endl;

  std::vector<int> v1 = GenVector::RandomVector(20, 10);
  std::vector<int> v2 = GenVector::RandomVector(20, 10);
  std::vector<int> vModified = OpsVector::ModifyVector(v1);
  std::vector<int> vSorted = OpsVector::SortVector(v1);
  std::vector<int> vSearched = OpsVector::SearchVector(v1, 27);
  std::vector<int> vReversed = OpsVector::ReverseVector(v1);
  std::vector<int> vRotated = OpsVector::RotateVector(v1, 5);
  std::vector<int> vMerged = OpsVector::MergeVectors(v1, v2);

  std::cout << "RandomVector(20): ";
  OpsVector::PrintVector(v1);

  std::cout << "ModifyVector(RandomVector(20)): ";
  OpsVector::PrintVector(vModified);

  std::cout << "SortVector(RandomVector(20)): ";
  OpsVector::PrintVector(vSorted);

  std::cout << "SearchVector(RandomVector(20), 27): ";
  OpsVector::PrintVector(vSearched);

  std::cout << "ReverseVector(RandomVector(20)): ";
  OpsVector::PrintVector(vReversed);

  std::cout << "RotateVector(RandomVector(20), 5): ";
  OpsVector::PrintVector(vRotated);

  std::cout << "MergeVectors(RandomVector(20), RandomVector(20)): ";
  OpsVector::PrintVector(vMerged);

  std::cout << std::endl;
}

void
_linkedlist() {
  std::cout << "LinkedList" << std::endl;
  std::cout << "----------" << std::endl;

  LinkedList linkedlist(10);
  linkedlist.Print();
  linkedlist.AddNode(27);
  linkedlist.AddNode(5);
  linkedlist.Print();
  std::cout << "SearchList(27): " << linkedlist.SearchList(27) << std::endl;
  std::cout << "SearchList(100): " << linkedlist.SearchList(100) << std::endl;
  linkedlist.ReverseList();
  linkedlist.Print();

  std::cout << std::endl;
}

void
_vectoralgebra() {
  std::cout << "Vector Algebra" << std::endl;
  std::cout << "--------------" << std::endl;

  int n = 20;
  std::vector<double> x = GenVector::RandomVectorDouble(n, -10, 10);
  std::vector<double> h = GenVector::RandomVectorDouble(3, -1, 1);
  OpsVector::PrintVector(x);
  OpsVector::PrintVector(h);

  std::vector<double> y = MathVectorAlgebra::Cubic(1, 2, 3, 4, x);
  std::cout << "Cubic(1, 2, 3, 4, x): ";
  OpsVector::PrintVector(y);

  std::vector<double> z = MathVectorAlgebra::Convolve(1, h, x);
  std::cout << "Convolve(1, h, x): ";
  OpsVector::PrintVector(z);
}

int
main(int argc, char **argv) {
  _single();
  _double();
  _strops();
  _primes();
  _sort();
  _vector();
  _linkedlist();
  _vectoralgebra();
  return 0;
}