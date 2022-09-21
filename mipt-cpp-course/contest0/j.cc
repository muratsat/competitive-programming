#include <iostream>

int Divisible(int a, int b) {
  return (a % b == 0) || (b % a == 0);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << Divisible(a, b) << '\n';
  return 0;
}
