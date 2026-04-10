#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string n, int h, int pwr) : Character(n, h, pwr) {};

void Sorcerer::attack() {
  std::cout << "Casts a spell!" << std::endl;
}
