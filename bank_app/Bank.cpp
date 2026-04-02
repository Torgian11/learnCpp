#include "Bank.hpp"
#include <iostream>

void Bank::createAccount(std::string accountNumber, double initialBalance) {
  BankAccount newAccount = BankAccount(accountNumber, initialBalance);
  accounts.push_back(newAccount);
}

BankAccount* Bank::findAccount(std::string accountNumber) {
  for (int i = 0; i < accounts.size(); ++i) {
    if (accounts[i].getAccountNumber() == accountNumber) {
      return &accounts[i];
    }
  }
  return nullptr;
}

int Bank::transferMoney(BankAccount& sourceAccount, BankAccount& destAccount, double amount) {
  std::string srcString = sourceAccount.getAccountNumber();
  std::string destString = destAccount.getAccountNumber();

  bool hasSource = (findAccount(srcString) != nullptr);
  bool hasDest = (findAccount(destString) != nullptr);

  if (hasSource && hasDest) {
    if (sourceAccount.getBalance() < amount) {
      return 3;
    }

    BankAccount::Transaction withdrawTx;
    BankAccount::Transaction depositTx;

    withdrawTx.withdraw(sourceAccount, amount);
    depositTx.deposit(destAccount, amount);

    return 1;
  }

  return 2;
}
