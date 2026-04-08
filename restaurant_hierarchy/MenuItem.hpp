#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

#include <string>
using namespace std;

class MenuItem {
 private:
  string name;
  double price;

public:
  MenuItem(string nme, double prc) : name(nme), price(prc) {};
  void display() const;
};

#endif
