#include "BankAccount.hpp"

std::string BankAccount::getAccountNumber() {
  return accountNumber;
}

double BankAccount::getBalance() {
  return balance;
}

void BankAccount::setAccountNumber(std::string newAccNum) {
  accountNumber = newAccNum;
}

void BankAccount::setBalance(double newBalance) {
  balance = newBalance;
}

void BankAccount::Transaction::deposit(BankAccount& destAccount, double amt){
          destAccount.balance += amt;
        };
void BankAccount::Transaction::withdraw(BankAccount& sourceAccount, double amt) {
  sourceAccount.balance -= amt;
};
