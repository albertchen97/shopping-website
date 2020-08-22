#include "Buyer.h"

Buyer::Buyer() : balance(100) {}; // Set initial balance to 100
int Buyer::getBalance() { return balance; }
void Buyer::setBalance(int newBalance) { balance = newBalance; }