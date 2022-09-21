#include <iostream>

int Max(int a, int b) {
  return (a > b) * a + (a <= b) * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << Max(a, b) << '\n';
  return 0;
}
