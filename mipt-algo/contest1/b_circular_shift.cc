#include <iostream>

using namespace std;

int CycleLength(const int* begin, const int* end) {
  const int* l = begin;
  const int* r = end;
  while (l < r) {
    const int* m = l + (r - l) / 2;

    if (*m < *r) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return l - begin;
}

void Solve() {
  int n;
  cin >> n;
  int a[100000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  cout << CycleLength(a, a + n - 1);
}

int main() {
  Solve();
  return 0;
}
