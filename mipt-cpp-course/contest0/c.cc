#include <iostream>

void OutputNext(int a) {
  std::cout << "The next number for the number " << a << " is " << a + 1
            << ".\n";
}

void OutputPrevious(int a) {
  std::cout << "The previous number for the number " << a << " is " << a - 1
            << ".\n";
}

int main() {
  int n = 0;
  std::cin >> n;
  OutputNext(n);
  OutputPrevious(n);
  return 0;
}