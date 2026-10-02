#include "posting.hpp"

namespace ledger {

bool post(Account& from, Account& to, long cents) {
  if (cents <= 0) return false;
  if (from.balance_cents() < cents) return false;
  from.debit(cents);
  to.credit(cents);
  return true;
}

}  // namespace ledger
