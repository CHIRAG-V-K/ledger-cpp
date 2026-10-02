#pragma once
#include <string>
#include <vector>

namespace ledger {

// One side of the book. Balances are cents, never floating point: a ledger that
// cannot add up is not a ledger.
class Account {
 public:
  Account(std::string name, long opening_cents);

  const std::string& name() const { return name_; }
  long balance_cents() const { return balance_cents_; }

  void credit(long cents);
  void debit(long cents);

 private:
  std::string name_;
  long balance_cents_;
};

}  // namespace ledger
