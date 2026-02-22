#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "functions.hpp"

// Source - https://stackoverflow.com/a/44973498
// Posted by Nicol Bolas, modified by community. See post 'Timeline' for change history
// Retrieved 2026-02-15, License - CC BY-SA 4.0

static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;
}

void bleep(std::string word, std::string &text) {
  std::stringstream ss(text);
  std::string segment;
  std::string newText = "";

  std::string bleeped = "";
  for (int i = 0; i < word.size(); i++) {
    bleeped += "*";
  }

  while (ss >> segment) {
    if (segment == word) {
      newText.append(bleeped + " ");
    } else {
      newText.append(segment + " ");
    }
  }

  std::string trimmed = ltrim(newText);
  text = trimmed;
  // for (int i = 0; i < text.size(); i++) {
  //     for (int j = 0; j < word.size(); j ++) {
  //       if (text[i] == word[j]) {
  //         text[i] = '*';
  //       };
  //     };
  //   };
};
