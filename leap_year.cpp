#include <iostream>
#include <cmath>

int countDigit(int n) {
    if (n == 0) {
      return 1;
    }
    int count = 0;
    while (n != 0) {
        n = floor(n / 10);
        ++count;
    }
    return count;
}

int main() {

  int year;
  std::cout << "Enter a 4 digit year: ";
  std::cin >> year;

  if (countDigit(year) != 4) {
    std::cout << "Invalid entry.\n";
    return 0;
  }

  if (year % 4 == 0 || year % 400 == 0) {
    std::cout << year << " is a leap year!";
  } else if (year % 100 == 0 && year % 400 != 0) {
    std::cout << year << " is not a leap year!";
  } else {
    std::cout << year << " is not a leap year!";
  }
  
}
