#include <algorithm>
#include <iostream>

using namespace std;

void Solve() {
  int n;
  cin >> n;

  const int kMaxSize = 100000;
  int a[kMaxSize] = {};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int min_l[kMaxSize];
  min_l[0] = a[0];
  for (int i = 1; i < n; i++) {
    min_l[i] = min(min_l[i - 1], a[i]);
  }

  int min_r[kMaxSize];
  min_r[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    min_r[i] = min(min_r[i + 1], a[i]);
  }

  int q;
  cin >> q;
  for (int k = 0; k < q; k++) {
    int l, r;
    cin >> l >> r;
    cout << min(min_l[l - 1], min_r[r - 1]) << '\n';
  }
}

int main() {
  Solve();
  return 0;
}