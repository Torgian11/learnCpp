#include "functions.hpp"
#include "DataHolder.hpp"

using namespace std;

void runToolkitDemo() {
  std::cout << midpoint(100,200) << std::endl;

  std::string part1 = "chassis";
  std::string part2 = "engine";

  swapValues(part1, part2);

  DataHolder specialNumber(2.71, 1.618, 9.8);
  std::cout << "Special number: " << specialNumber.getValue() << std::endl;

  DataHolder<std::string> robotName("Codey the Robot");
  std::cout << robotName.getValue() << std::endl;
}
int main() {
  std::cout << midpoint(10, 20) << std::endl;
  std::cout << midpoint(2.71, 3.14) << std::endl;

  int firstNumber = 5;
  int secondNumber = 10;
  swapValues(firstNumber, secondNumber);
  std::cout << firstNumber << ", " << secondNumber << std::endl;
  std::string greeting = "Hello";
  std::string planet = "world";
  swapValues(greeting, planet);
  std::cout << greeting << ", " << planet << std::endl;

  DataHolder testNumber(42, 0, 100);
  std::cout<< "test Number Value: " << testNumber.getValue() << std::endl;

  testNumber.setValue(75);
  std::cout<< "test Number Value: " << testNumber.getValue() << std::endl;

  testNumber.setValue(150);
  std::cout<< "test Number Value: " << testNumber.getValue() << std::endl;

  testNumber.setValue(-4);
  std::cout<< "test Number Value: " << testNumber.getValue() << std::endl;
  
  DataHolder<std::string> testString("robotics lab");
  std::cout << "test string value: " << testString.getValue() << std::endl;

  std::cout << "TOOL KIT DEMO" << std::endl;

  runToolkitDemo();
  
}
