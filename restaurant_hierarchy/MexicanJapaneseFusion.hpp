#ifndef MEXICAN_JAPANESE_FUSION_HPP
#define MEXICAN_JAPANESE_FUSION_HPP

#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "Restaurant.hpp"

class MexicanJapaneseFusion : public MexicanRestaurant, public JapaneseRestaurant {
  public:
    MexicanJapaneseFusion(std::string nme, std::string addr, int spiceLvl, bool tatamiAvailable) : Restaurant(nme, addr), MexicanRestaurant(nme, addr, spiceLvl), JapaneseRestaurant(nme, addr, tatamiAvailable){};
    void describeCuisine();
    void displaySpecialty();
};

#endif
