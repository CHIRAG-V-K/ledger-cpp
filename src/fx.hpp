#pragma once
#include <string>

namespace ledger {

// Converts between currencies using the daily rate.
double convert(double amount, const std::string& from, const std::string& to);

}  // namespace ledger
