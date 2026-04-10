#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

using namespace std;

class Character {
  private:
    string name;
    int health;
    int power;
  public:
    Character(string n, int h, int pwr);
    void virtual attack();
    void virtual displayInfo();
    string getName() const { return name; };
};

#endif 
