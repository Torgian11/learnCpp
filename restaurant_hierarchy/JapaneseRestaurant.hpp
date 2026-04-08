#ifndef JAPANESE_RESTAURANT_HPP
#define JAPANESE_RESTAURANT_HPP

#include "Restaurant.hpp"

class JapaneseRestaurant : virtual public Restaurant {
  private:
    bool hasTatami;
  public:
    JapaneseRestaurant(std::string nme, std::string addr, bool tatamiAvailable) : Restaurant(nme, addr), hasTatami(tatamiAvailable) {};
    void describeCuisine();
};

#endif
