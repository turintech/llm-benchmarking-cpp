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
  ext::shared_ptr<EuropeanExercise> europeanExercise(new EuropeanExercise(maturity));
  Handle<Quote> underlyingH(ext::shared_ptr<Quote>(new SimpleQuote(underlyingPrice)));
  Handle<YieldTermStructure> flatTermStructure(
      ext::shared_ptr<YieldTermStructure>(new FlatForward(0, TARGET(), riskFreeRate, Actual365Fixed())));
  Handle<BlackVolTermStructure> flatVolTS(
      ext::shared_ptr<BlackVolTermStructure>(new BlackConstantVol(0, TARGET(), volatility, Actual365Fixed())));
  ext::shared_ptr<StrikedTypePayoff> payoff(new PlainVanillaPayoff(type, strike));
  ext::shared_ptr<BlackScholesMertonProcess> bsmProcess(
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

/** @brief Prices a fixed rate bond
 *
 * @param faceValue
 * @param couponRate
 * @param issueDate
 * @param maturityDate
 * @param frequency
 * @param dayCounter
 *
 * Usage:
     Real faceValue = 1000.0;
     Real couponRate = 0.05;
     Date issueDate(1, January, 2022);
     Date maturityDate(1, January, 2032);
     Frequency frequency = Semiannual;
     DayCounter dayCounter = ActualActual(ActualActual::ISMA);
 */
Real
LibQuantLib::FixedRateBond(Real faceValue, Real couponRate, Date issueDate, Date maturityDate, Frequency frequency,
                           DayCounter dayCounter) {
  // Create a schedule of coupon payment dates
  Schedule schedule(issueDate, maturityDate, Period(frequency), TARGET(), ModifiedFollowing, ModifiedFollowing,
                    DateGeneration::Backward, false);

  // Calculate cash flows
  std::vector<Rate> couponRates(schedule.size() - 1, couponRate);
  std::vector<Real> notionals(schedule.size() - 1, faceValue);
  notionals.back() += faceValue;   // Add face value to the last payment
  Leg cashFlows = FixedRateLeg(schedule).withNotionals(notionals).withCouponRates(couponRates, dayCounter);

  // Discount cash flows manually
  ext::shared_ptr<YieldTermStructure> discountCurve(
      ext::shared_ptr<YieldTermStructure>(new FlatForward(0, TARGET(), 0.05, ActualActual(ActualActual::ISMA))));

  Date valuationDate = Settings::instance().evaluationDate();

  return CashFlows::npv(cashFlows, *discountCurve, true, valuationDate);
}
