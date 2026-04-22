#include <iostream>
#include <vector>
#include "Color.hpp"

int main() {
  std::cout << std::boolalpha;  // print bools as true/false

  // You can give this color in two equivalent ways:
  //
  // 1. Hex (base-16): 0x50C878
  // 2. Decimal RGB (base-10): 80, 200, 120
  //
  // Each pair of hex digits converts to its decimal RGB value:
  // 0x50 → 80, 0xC8 → 200, 0x78 → 120
  Color emerald = Color::fromHexLiteral("#50c878");
  Color sunset = Color::fromHexLiteral("#ff4500");
  Color ocean  = Color::fromHexLiteral("#1e90ff");
  Color dusk = (sunset + ocean);
  std::vector<int> warmUp = {30, -10, -10};
  Color warmedUp = dusk + warmUp;
  
  std::cout << emerald[0] << std::endl;
  std::cout << emerald[1] << std::endl;
  std::cout << emerald[2] << std::endl;

  std::cout << "Dusk: " << dusk << std::endl;
  std::cout << "Warmed up: " << warmedUp << std::endl;

  std::cout << "Dusk incremented: " << ++dusk << std::endl;
  std::cout << "Sunset decremented: " << --sunset << std::endl;

  Color duskBoost = (dusk * 2);
  std::cout << "Dusk Boosted: " << duskBoost << std::endl;

  Color inverseDusk = dusk(ColorUtility::invert);
  std::cout << "Inverse of dusk: " << inverseDusk << std::endl;

  // Bug here. Must be false. Probably a pass by reference that is changing dusk when something is modified in another variable.
  bool isEquivelent = (dusk == duskBoost);
  std::cout << "Equivelent? " << isEquivelent << std::endl;
}
