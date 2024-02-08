#include <iostream>
#include <ql/quantlib.hpp>

#include "libraries/quantlib.h"

using namespace QuantLib

    void
    _quantlib() {
  std::cout << "Quantlib" << std::endl;
  std::cout << "--------" << std::endl;

  Real npv = LibQuantLib::PriceOption(100.0, 100.0, 0.05, 0.20, maturity(20, September, 2024));
  std::cout << npv << std::endl;
}

int
main(int argc, char **argv) {
  _quantlib();
  return 0;
}
