#include <iostream>
#include <vector>
#include <string>

int main() {
  std::string words = "turpentine and turtles";
  std::vector<char> vowels = {'a','e','i','o','u'};
  std::vector<char> result = {};

  for (int i = 0; i < words.size(); i++) {
    for (int j = 0; j < vowels.size(); j++) {
      if (words[i] == vowels[j]) {
        if (words[i] == 'e') {
          result.push_back('e');
          result.push_back('e');
        } else if (words[i] == 'u') {
          result.push_back('u');
          result.push_back('u');
        } else {
          result.push_back(words[i]);
        }
      }
    }
  };

  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i];
  }
}
