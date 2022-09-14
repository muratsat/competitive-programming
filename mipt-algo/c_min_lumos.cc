#include <algorithm>
#include <iostream>

using namespace std;

bool CheckLength(const int* begin, const int* end, long long length, int k) {
  long long covered = *begin - 1;
  int count = 0;

  for (const int* it = begin; it <= end; ++it) {
    long long x = *it;
    if (covered < x) {
      covered = x + length;
      count++;
    }
    if (count > k) {
      return false;
    }
  }

  return true;
}

long long FindMinLength(const int* begin, const int* end, int k) {
  long long l = 0;
  long long r = *end - *begin;

  while (l < r) {
    long long m = l + (r - l) / 2;
    if (CheckLength(begin, end, m, k)) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  return l;
}

void Solve() {
  int n, k;
  cin >> n >> k;

  int* x = new int[n];
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  sort(x, x + n);
  cout << FindMinLength(x, x + n - 1, k) << '\n';

  delete[] x;
}

int main() {
  Solve();
  return 0;
}
