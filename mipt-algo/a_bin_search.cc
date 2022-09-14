#include <iostream>

using namespace std;

bool BinarySearch(const int* begin, const int* end, int target) {
  const int* l = begin;
  const int* r = end - 1;
  while (l <= r) {
    const int* m = l + (r - l) / 2;

    if (*m < target) {
      l = m + 1;
    } else if (*m > target) {
      r = m - 1;
    } else {
      return true;
    }
  }
  return false;
}

void Solve() {
  int n;
  cin >> n;
  int a[100000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int q;
  cin >> q;
  for (int k = 0; k < q; k++) {
    int i, j, t;
    cin >> i >> j >> t;
    cout << (BinarySearch(&a[i], &a[j], t) ? "YES\n" : "NO\n");
  }
}

int main() {
  Solve();
  return 0;
}
