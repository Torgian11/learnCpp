#include <iostream>
#include <string>

template <typename T>
T midpoint(T a, T b) {
  T m = a + ((b-a) / 2);
  return m;
}

template <typename T>
void swapValues(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}
