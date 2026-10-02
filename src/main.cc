#include <iostream>

#include "account.hpp"
#include "posting.hpp"

int main() {
  ledger::Account cash("cash", 10'000);
  ledger::Account rent("rent", 0);

  if (!ledger::post(cash, rent, 2'500)) {
    std::cerr << "posting refused\n";
    return 1;
  }
  std::cout << cash.name() << ": " << cash.balance_cents() << '\n';
  std::cout << rent.name() << ": " << rent.balance_cents() << '\n';
  return 0;
}
