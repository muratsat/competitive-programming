#include <iostream>

struct Time {
  int h;
  int m;
  int s;
};

Time GetTime() {
  Time t;
  std::cin >> t.h >> t.m >> t.s;
  return t;
}

int ToSeconds(int h, int m, int s) {
  return h * 3600 + m * 60 + s;
}

int TimeDiff(Time t1, Time t2) {
  return ToSeconds(t2.h, t2.m, t2.s) - ToSeconds(t1.h, t1.m, t1.s);
}

int main() {
  Time t1 = GetTime();
  Time t2 = GetTime();

  std::cout << TimeDiff(t1, t2) << '\n';

  return 0;
}
