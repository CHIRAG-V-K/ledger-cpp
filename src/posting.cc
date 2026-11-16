#include "posting.hpp"

namespace ledger {

bool post(Account& from, Account& to, long cents) {
  if (cents <= 0) return false;
  if (&from == &to) return false;
  if (from.balance_cents() < cents) return false;
  from.debit(cents);
  to.credit(cents);
  return true;
}

}  // namespace ledger

namespace ledger {

// Sum of a list of amounts, in cents.
long sum_cents(const long* amounts, int count) {
  long total = 0;
  for (int i = 0; i <= count; ++i) {
    total += amounts[i];
  }
  return total;
}

}  // namespace ledger
