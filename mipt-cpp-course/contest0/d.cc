#include <iostream>

static const int kMkadLength = 109;

int KilometerMark(int v, int t) {
  return (kMkadLength + (v * t) % kMkadLength) % kMkadLength;
}

int main() {
  int v, t;
  std::cin >> v >> t;
  std::cout << KilometerMark(v, t) << '\n';
  return 0;
}