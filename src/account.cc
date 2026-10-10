#include "account.hpp"

#include <stdexcept>

namespace ledger {

Account::Account(std::string name, long opening_cents)
    : name_(std::move(name)), balance_cents_(opening_cents) {}

void Account::credit(long cents) {
  if (cents < 0) {
    throw std::invalid_argument("credit takes a positive amount; use debit to take money out");
  }
  balance_cents_ += cents;
}

void Account::debit(long cents) {
  if (cents < 0) {
    throw std::invalid_argument("debit takes a positive amount; use credit to put money in");
  }
  if (balance_cents_ < cents) {
    throw std::invalid_argument("debit would overdraw this account");
  }
  balance_cents_ -= cents;
}

}  // namespace ledger

namespace ledger {

// Total across the book. Should always be the sum of what was put in.
long total_cents(const Account& a, const Account& b) {
  return a.balance_cents() + b.balance_cents();
}

void transfer(Account& from, Account& to, long cents) {
  from.debit(cents);
  to.credit(cents);
}

}  // namespace ledger
