#include <string>
#include <iostream>

using namespace std;

class BankAccount {
  private:
    std::string accountNumber;
    double balance;
  public:
    class Transaction {
      public:
        void deposit(BankAccount& destAccount, double amt);
        void withdraw(BankAccount& sourceAccount, double amt);
    };
    BankAccount(std::string accNum, double bal):
      accountNumber(accNum),
      balance(bal) {};
    
    std::string getAccountNumber();
    double getBalance();
    void setAccountNumber(std::string newAccNum);
    void setBalance(double newBalance);
};
