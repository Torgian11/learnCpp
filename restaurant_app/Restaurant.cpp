#include "Restaurant.hpp"
#include <sstream>

Restaurant::Restaurant() : id(0) {}

Restaurant::Restaurant(int id, string name, string cuisine)
  : id(id), name(move(name)), cuisine(move(cuisine)) {}

void Restaurant::addMenuItem(const string& menuItemEntry) {
  menuItems.push_back(menuItemEntry);
}

int Restaurant::getId() const {
  return id;
}

const string& Restaurant::getName() const {
  return name;
}

const string& Restaurant::getCuisine() const {
  return cuisine;
}

const vector<string>& Restaurant::getMenu() const {
  return menuItems;
}

ostream& operator<<(ostream& outputStream, const Restaurant& restaurant) {
  outputStream << restaurant.id << "#" << restaurant.name << "#" << restaurant.cuisine << "#" << restaurant.menuItems.size();
  for (auto& item : restaurant.menuItems) {
    outputStream << item;
  }
  return outputStream;
}

istream& operator>>(istream& inputStream, Restaurant& restaurant) {
  restaurant.menuItems.clear();

  return inputStream;
}
