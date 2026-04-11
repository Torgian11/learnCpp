#include "Cat.hpp"
#include <iostream>
using namespace std;

void Cat::makeSound() {
  std::cout << getName() << " is meowing! Meow!" << std::endl;
}
