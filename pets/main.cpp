#include "Pet.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "MagicPet.hpp"
#include <iostream>
#include <vector>
#include <memory> // for smart pointers
using namespace std;

int main() {
  Dog myDog;
  Cat myCat;
  MagicPet myMagicPet;

  myDog.setName("Dudley");
  myDog.setAge(1);

  myCat.setName("Donut");
  myCat.setAge(2);

  myMagicPet.setName("Froggy");
  myMagicPet.setAge(44);

  vector<Pet*> pets;
  pets.push_back(&myDog);
  pets.push_back(&myCat);
  pets.push_back(&myMagicPet);

  for (Pet* pet : pets) {
    pet -> makeSound();

    MagicPet* magPet = dynamic_cast<MagicPet*>(pet);
    if (magPet) {
      magPet -> doTrick();
    }


  }
  return 0;
}
