#include "Restaurant.hpp"
#include <iostream>

void Restaurant::displayInfo() {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Address: " << address << std::endl;
}

void Restaurant::describeCuisine() {
  std::cout << "This restaurant serves various types of cuisines." << std::endl;
}

void Restaurant::addMenuItem(MenuItem item) {
  menu.push_back(item);
}

void Restaurant::displayMenu() {
  std::cout << name << " Menu:" << std::endl;
  for (const auto& item : menu) {
    item.display();
  }
}
