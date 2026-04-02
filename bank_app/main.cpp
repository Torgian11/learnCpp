#include <iostream>
#include "Bank.hpp"

using namespace std;

int main() {
  Bank myBank;
  myBank.createAccount("1001", 5000);
  myBank.createAccount("1002", 3000);
  myBank.createAccount("1003", 2000);

  BankAccount* account1 = myBank.findAccount("1001");
  BankAccount* account2 = myBank.findAccount("1002");
  BankAccount* account3 = myBank.findAccount("1003");

  if (account1 != nullptr && account2 != nullptr) {
    BankAccount::Transaction depositTransaction;
    BankAccount::Transaction withdrawTransaction;

    depositTransaction.deposit(*account1, 1000);
    withdrawTransaction.withdraw(*account2, 500);

    std::cout << "Balance in account1: " << account1->getBalance() << std::endl;
    std::cout << "Balance in account2: " << account2->getBalance() << std::endl;

    int result = myBank.transferMoney(*account1, *account2, 1000);

    if (result == 1) {
      std::cout << "Transfer successful!" << std::endl;
    }

    if (result == 2) {
      std::cout << "Account(s) not found!" << std::endl;
    }

    if (result == 3) {
      std::cout << "Insufficient funds!" << std::endl;
    }
  }
  
  return 0;
}
