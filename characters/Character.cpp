#include "Character.hpp"

Character::Character(std::string n = "Elden King", int h = 100, int pwr = 10) {
  this->name = n;
  this->health = h;
  this->power = pwr;
}

void Character::attack() {
  std::cout << "Basic Low Attack" << std::endl;
}

void Character::displayInfo() {
  std::cout << "Name: " << name << ", Health: " << health << ", Power: " << power << std::endl;
}
