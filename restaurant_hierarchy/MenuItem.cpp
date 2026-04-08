#include "MenuItem.hpp"
#include <iostream>
#include <iomanip>

void MenuItem::display() const {
  std::cout << name << " - $" << fixed << setprecision(2) << price << std::endl;
}
