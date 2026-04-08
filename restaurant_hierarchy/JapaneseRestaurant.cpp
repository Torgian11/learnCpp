#include "JapaneseRestaurant.hpp"
#include <iostream>

void JapaneseRestaurant::describeCuisine() {
  if (hasTatami) {
    std::cout << "Traditional Japanese cuisine with tatami seating available" << std::endl;
  } else {
    std::cout << "Traditional Japanese cuisine" << std::endl;
  }
}
