#include <iostream>

int main() {
  
  int pesos, reais, soles;
  double dollars;

  std::cout << "Enter number of Colombian Pesos: ";
  std::cin >> pesos;
  std::cout << "Enter amount of Reais: ";
  std::cin >> reais;
  std::cout << "Enter amount of Soles: ";
  std::cin >> soles;
  // Current exchange rate
  dollars = (.06 * pesos) + (.19 * reais) + (.3 * soles);
  std::cout << "US Dollars = $" << dollars << "\n";
  return 0;
}
