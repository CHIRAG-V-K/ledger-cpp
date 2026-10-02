#pragma once
#include "account.hpp"

namespace ledger {

// Moves money between two accounts, or moves none at all. A posting that
// half-applied would leave the book unbalanced, which is the one state this
// type exists to make unreachable.
bool post(Account& from, Account& to, long cents);

}  // namespace ledger
