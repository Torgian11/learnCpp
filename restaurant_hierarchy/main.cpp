#include <iostream>
#include "MexicanRestaurant.hpp"
#include "JapaneseRestaurant.hpp"
#include "MexicanJapaneseFusion.hpp"
#include "MenuItem.hpp"

using namespace std;

int main() {
    cout << "Testing Restaurant Inheritance Hierarchy:" << endl;

    MexicanRestaurant casa = MexicanRestaurant("La Casa", "123 Spice Lane", 4);
    JapaneseRestaurant sakuran = JapaneseRestaurant("Sakura", "456 Sushi Road", true);
    MexicanJapaneseFusion japmex = MexicanJapaneseFusion("Fusion Fiesta", "789 Fusion Ave", 3, true);

    casa.displayInfo();
    casa.describeCuisine();
    
    sakuran.displayInfo();
    sakuran.describeCuisine();

    japmex.displayInfo();
    japmex.describeCuisine();
    japmex.displaySpecialty();

    casa.addMenuItem(MenuItem("Tacos", 8.99));
    casa.addMenuItem(MenuItem("Enchiladas", 12.99));

    sakuran.addMenuItem(MenuItem("Sushi Roll", 14.99));
    sakuran.addMenuItem(MenuItem("Ramen", 11.99));

    japmex.addMenuItem(MenuItem("Sushi Tacos", 15.99));
    japmex.addMenuItem(MenuItem("Wasabi Guacamole", 7.99));

    casa.displayMenu();
    sakuran.displayMenu();
    japmex.displayMenu();
    return 0;
}
