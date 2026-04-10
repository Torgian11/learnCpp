#include <vector>
#include "Warrior.hpp"
#include "Sorcerer.hpp"

using namespace std;

int main() {

  vector<Character*> characters;

  Warrior* charOne = new Warrior("John", 100, 50);
  Sorcerer* charTwo = new Sorcerer("Sal", 50, 100);

  characters.push_back(charOne);
  characters.push_back(charTwo);

  for (Character* c : characters) {
    c -> attack();
    c -> displayInfo();
  };

  Character* characterPtr = new Warrior("Alex", 100, 45);
  Warrior* warPtr = dynamic_cast<Warrior*>(characters[0]);
  if (warPtr) {
    warPtr->attack();
    warPtr->specialAttack();
  }

  for (Character* c : characters) {
    delete c;
  }

  characters.clear();
  return 0;
}
