#ifndef _LIB_QUANTLIB_H_
#define _LIB_QUANTLIB_H_

#include <iostream>
#include <ql/quantlib.hpp>

using namespace QuantLib;

namespace LibQuantLib {

Real PriceOption(Real underlyingPrice, Real strike, Real riskFreeRate, Volatility volatility, Date maturity);
Real FixedRateBond(Real faceValue, Real couponRate, Date issueDate, Date maturityDate, Frequency frequency,
                   DayCounter dayCounter);
}   // namespace LibQuantLib

#endif   // !_LIB_QUANTLIB_H_
