#include <iostream>
#include <string>
#include "functions.hpp"

int main() {
  std::string word = "broccoli";
  std::string text = "bananan broccoli when we go broccoli to broccoli.";
  bleep(word, text);
  std::cout << text;
  return 0;
}
