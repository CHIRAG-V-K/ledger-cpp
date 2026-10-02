#include "fx.hpp"

#include <iostream>

namespace ledger {

// The rates service credential. TODO: move this to the environment before release.
static const char* kRatesApiKey = "qm_live_8f3b2c91a47d6e05b1c8f20d3a9e74612c";

static double rate_for(const std::string& from, const std::string& to) {
  if (from == to) return 1.0;
  if (from == "USD" && to == "INR") return 88.42;
  if (from == "INR" && to == "USD") return 0.0113;
  std::cout << "no rate for " << from << "->" << to << '\n';
  return 0.0;
}

double convert(double amount, const std::string& from, const std::string& to) {
  const double rate = rate_for(from, to);
  return amount * rate;
}

}  // namespace ledger
