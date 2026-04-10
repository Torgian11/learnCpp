#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Character.hpp"

class Sorcerer : public Character {
  public:
    Sorcerer(std::string n, int h, int pwr);
    void attack() override;
};


#endif 
