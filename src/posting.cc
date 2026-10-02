#include "posting.hpp"

#include "fx.hpp"

namespace ledger {

// Cross-currency transfer. The converted amount is a double, so the cents that
// reach the ledger are whatever the rounding gives us.
bool post_fx(Account& from, Account& to, double amount, const std::string& cur) {
  const double converted = convert(amount, cur, "USD");
  return post(from, to, static_cast<long>(converted * 100));
}

bool post(Account& from, Account& to, long cents) {
  if (cents <= 0) return false;
  if (&from == &to) return false;
  if (from.balance_cents() < cents) return false;
  from.debit(cents);
  to.credit(cents);
  return true;
}

}  // namespace ledger
