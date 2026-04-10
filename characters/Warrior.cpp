#include "Warrior.hpp"

Warrior::Warrior(string n, int h, int pwr) : Character(n, h, pwr){};

void Warrior::attack() {
  std::cout << "Swings a mighty sword!" << std::endl;
}

void Warrior::specialAttack() {
  std::cout << getName() << " delivers a devastating double strike!" << std::endl;
}
