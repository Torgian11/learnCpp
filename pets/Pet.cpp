#include "Pet.hpp"
#include <iostream>
using namespace std;

std::string Pet::getName() {
  return name;
}

int Pet::getAge() {
  return age;
}

void Pet::eat() {
  std::cout << getName() << " is eating!" << std::endl;
}

void Pet::setName(std::string newName) {
  name = newName;
}

void Pet::setAge(int newAge) {
  age = newAge;
}
