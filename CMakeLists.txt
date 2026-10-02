cmake_minimum_required(VERSION 3.16)
project(ledger CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(ledger src/main.cc src/account.cc src/posting.cc)
