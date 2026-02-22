#include <iostream>

int main() {
  double weight;
  std::cout << "What is your earth weight in pounds? ";
  std::cin >> weight;

  int number;

  std::cout << "Enter a number for which planet you wish to fight on: \n 1: Mercury\n 2: Venus\n 3: Mars\n 4: Jupiter\n 5: Saturn\n 6: Uranus\n 7: Neptune\n ";
  std::cin >> number;
  switch(number) {
    case 1:
      std::cout << "Weight is: " << 0.38 * weight << " pounds\n";
      break;
    case 2:
      std::cout << "Weight is: " << 0.91 * weight << " pounds\n";
      break;
    case 3:
      std::cout << "Weight is: " << 0.38 * weight << " pounds\n";
      break;
    case 4:
      std::cout << "Weight is: " << 2.34 * weight << " pounds\n";
      break;
    case 5:
      std::cout << "Weight is: " << 1.06 * weight << " pounds\n";
      break;
    case 6:
      std::cout << "Weight is: " << 0.92 * weight << " pounds\n";
      break;
    case 7:
      std::cout << "Weight is: " << 1.19 * weight << " pounds\n";
      break;
    default:
      std::cout << "That is not a valid selection." << " pounds\n";
      break;
  }
  
  return 0;
}
