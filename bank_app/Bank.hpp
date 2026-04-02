#include <vector>
#include "BankAccount.hpp"
class Bank {
  private:
    vector<BankAccount> accounts;
  public:
    void createAccount(std::string accountNumber, double initialBalance);
    BankAccount* findAccount(std::string accountNumber);
    int transferMoney(BankAccount& sourceAccount, BankAccount& destAccount, double amount);
};
