#include "quantlib.h"

/** @brief Prices a european option
 *
 * @param underlyingPrice
 * @param strike
 * @param riskFreeRate
 * @param volatility
 * @param maturity
 *
 * Usage:
 *   Real underlyingPrice = 100.0;
 *   Real strike = 100.0;
 *   Rate riskFreeRate = 0.05;
 *   Volatility volatility = 0.20;
 *   Date maturity(20, September, 2024);
 */
Real
LibQuantLib::PriceOption(Real underlyingPrice, Real strike, Rate riskFreeRate, Volatility volatility, Date maturity) {

  // Option type
  Option::Type type(Option::Call);

  // Constructing the European option
  EuropeanExercise europeanExercise(maturity);
  Handle<Quote> underlyingH(boost::shared_ptr<Quote>(new SimpleQuote(underlyingPrice)));
  Handle<YieldTermStructure> flatTermStructure(
      boost::shared_ptr<YieldTermStructure>(new FlatForward(0, TARGET(), riskFreeRate, Actual365Fixed())));
  Handle<BlackVolTermStructure> flatVolTS(
      boost::shared_ptr<BlackVolTermStructure>(new BlackConstantVol(0, TARGET(), volatility, Actual365Fixed())));
  boost::shared_ptr<StrikedTypePayoff> payoff(new PlainVanillaPayoff(type, strike));
  boost::shared_ptr<BlackScholesMertonProcess> bsmProcess(
      new BlackScholesMertonProcess(underlyingH, flatTermStructure, flatTermStructure, flatVolTS));

  // Create a European option
  VanillaOption europeanOption(payoff, europeanExercise);

  // Pricing using Monte Carlo with low number of paths (suboptimal)
  Size numPaths = 100;   // Very low number of paths
  boost::shared_ptr<PricingEngine> mcengine;
  mcengine = MakeMCEuropeanEngine<PseudoRandom>(bsmProcess).withSteps(10).withAbsoluteTolerance(0.02).withSeed(42);

  europeanOption.setPricingEngine(mcengine);
  return europeanOption.NPV();
}
