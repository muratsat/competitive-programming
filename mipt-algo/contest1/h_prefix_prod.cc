#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

void Solve() {
  // sum of first i logs of array
  // prefix_log[i] = log(a[1]) + ... + log(a[i])
  double prefix_log[300001] = {0};

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double a;
    cin >> a;
    prefix_log[i + 1] = prefix_log[i] + log(a);
  }

  int q;
  cin >> q;
  for (int k = 0; k < q; k++) {
    int i, j;
    cin >> i >> j;

    double log_sum = prefix_log[j + 1] - prefix_log[i];
    double m = j - i + 1;
    double geom_mean = exp(log_sum / m);

    cout << fixed << setprecision(10) << geom_mean << '\n';
  }
}

int main() {
  Solve();
  return 0;
}
