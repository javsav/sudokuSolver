#include <iostream>
#include <cmath>

int add(int a, int b) {
  std::cout << "a: " << a << ", b: " << b << "\n";
  if (b == 0) {
    return a;
  }
  return add(a, b - 1) + 1;
}

int main() {
  std::cout << add(4,8) << "\n";
}