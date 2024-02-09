#include <iostream>
#include <ql/quantlib.hpp>

#include "libraries/quantlib.h"

using namespace QuantLib;

void
_quantlib() {
  std::cout << "Quantlib" << std::endl;
  std::cout << "--------" << std::endl;

  Real npv0 = LibQuantLib::PriceOption(100.0, 100.0, 0.05, 0.20, Date(20, September, 2024));
  std::cout << npv0 << std::endl;

  Real FixedRateBond(Real faceValue, Real couponRate, Date issueDate, Date maturityDate, Frequency frequency,
                     DayCounter dayCounter);
  Real npv1 = LibQuantLib::FixedRateBond(1000.0, 0.05, Date(1, January, 2022), Date(1, January, 2032), Semiannual,
                                         ActualActual(ActualActual::ISMA));
  std::cout << npv1 << std::endl;
}

int
main(int argc, char **argv) {
  _quantlib();
  return 0;
}
