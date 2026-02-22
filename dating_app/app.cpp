#include <iostream>
#include "profile.hpp"

int main() {
  Profile sam("Sam Drakkila", 30, "New York", "USA", "he/him");

  sam.add_hobby("riding bicycles");
  sam.add_hobby("eating croissants");
  sam.add_hobby("finding a girl to be a 6 to his 9");

  std::cout << sam.view_profile();
}
