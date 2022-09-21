#include <iostream>

int Max(int a, int b) {
  return (a > b) * a + (a <= b) * b;
}

void Solve() {
  int h, a, b;
  std::cin >> h >> a >> b;

  h = Max(h - a, 0);
  int days = 1 + h / (a - b) + (h % (a - b) != 0);
  std::cout << days << '\n';
}

int main() {
  Solve();
  return 0;
}