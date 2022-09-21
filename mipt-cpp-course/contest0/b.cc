#include <iostream>
#include <cmath>

double Hypotenuse(int a, int b) {
  return std::sqrt(a * a + b * b);
}

int main() {
  int a = 0, b = 0;
  std::cin >> a >> b;
  std::cout << Hypotenuse(a, b) << '\n';
  return 0;
}