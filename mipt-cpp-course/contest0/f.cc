#include <iostream>

int NextEven(int n) {
  return n + 2 - n % 2;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << NextEven(n) << '\n';
  return 0;
}
