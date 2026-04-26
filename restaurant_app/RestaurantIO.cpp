#include "RestaurantIO.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

void addRestaurant(vector<Restaurant>& database) {
  int restaurantId, menuItemCount;
  string restaurantName, cuisineType;
  
  std::cout << "Enter restaurant ID: ";
  cin >> restaurantId;

  std::cout << "Enter restaurant name: ";
  cin.ignore();
  getline(cin, restaurantName);

  std::cout << "Enter cuisine type: ";
  cin.ignore();
  getline(cin, cuisineType);
  Restaurant newRestaurant(restaurantId, restaurantName, cuisineType);
  database.push_back(newRestaurant);
}

void displayRestaurants(const vector<Restaurant>& database) {
  for (const auto& restaurant : database) {
    cout << "\nID: " << restaurant.getId()
         << "\nName: " << restaurant.getName()
         << "\nCuisine: " << restaurant.getCuisine()
         << "\nMenu:\n";

    for (const auto& menuItemEntry : restaurant.getMenu()) {
      cout << "  - " << menuItemEntry << '\n';
    }
  }
}

bool loadDatabase(vector<Restaurant>& database, const string& filename) {
  ifstream inputFile(filename);
  if (!inputFile) {
    cerr << "[WARN] Could not open " << filename << " for reading.\n";
    return false;
  }

  Restaurant restaurant;
  while (inputFile >> restaurant) {
    database.push_back(restaurant);
  }
  return true;
}

void saveDatabase(const vector<Restaurant>& database, const string& filename) {
  ofstream outputFile(filename);
  if (!outputFile.is_open()) {
    cerr << "[ERR] Could not open " << filename << " for writing.\n";
    return;
  }

  for (const auto& restaurant : database) {
    outputFile << restaurant << endl;
  }
  outputFile.close();
}
