#include <iomanip>
#include <iostream>

static const int kSecondsInMinute = 60;
static const int kSecondsInHour = 60 * kSecondsInMinute;
static const int kSecondsInDay = 24 * kSecondsInHour;

void Output(int total_seconds) {
  total_seconds %= kSecondsInDay;
  int hours = total_seconds / kSecondsInHour;
  int minutes = (total_seconds % kSecondsInHour) / kSecondsInMinute;
  int seconds = total_seconds % kSecondsInMinute;

  std::cout << hours << ':';
  std::cout << std::setfill('0') << std::setw(2) << minutes << ':';
  std::cout << std::setfill('0') << std::setw(2) << seconds << '\n';
}

int main() {
  int n = 0;
  std::cin >> n;
  Output(n);
  return 0;
}
