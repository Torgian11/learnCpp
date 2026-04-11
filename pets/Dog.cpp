#include "Dog.hpp"
#include <iostream>
using namespace std;

void Dog::makeSound() {
  std::cout << getName() << " is barking! Woof!" << std::endl;
}
