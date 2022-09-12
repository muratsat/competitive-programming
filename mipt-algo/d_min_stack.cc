#include <iostream>
#include <string>

using namespace std;

struct Pair {
  int first, second;
};

static const int kMaxStackSize = 200000;

struct Minqueue {
  int Push(int n);
  int Pop();
  int Back();
  int Min();
  int Size();
  int Clear();

 private:
  Pair item_[kMaxStackSize];
  int size_ = 0;
};

int Minqueue::Push(int n) {
  item_[size_].first = n;
  int min = n;
  if (size_ > 0 && item_[size_ - 1].second < min) {
    min = item_[size_ - 1].second;
  }
  item_[size_].second = min;
  size_++;
  return 0;
}

int Minqueue::Pop() {
  if (size_ == 0) {
    return -1;
  }
  size_--;
  return item_[size_].first;
}

int Minqueue::Back() {
  if (size_ == 0) {
    return -1;
  }
  return item_[size_ - 1].first;
}

int Minqueue::Min() {
  if (size_ == 0) {
    return -1;
  }
  return item_[size_ - 1].second;
}

int Minqueue::Size() { return size_; }

int Minqueue::Clear() {
  size_ = 0;
  return 0;
}

static void HandleError(int result) {
  if (result == -1) {
    cout << "error\n";
  } else {
    cout << result << '\n';
  }
}

static void HandleCommand(string command, Minqueue& stack) {
  if (command == "push") {
    int n;
    cin >> n;
    stack.Push(n);
    cout << "ok\n";
  } else if (command == "pop") {
    HandleError(stack.Pop());
  } else if (command == "back") {
    HandleError(stack.Back());
  } else if (command == "min") {
    HandleError(stack.Min());
  } else if (command == "size") {
    cout << stack.Size() << '\n';
  } else if (command == "clear") {
    stack.Clear();
    cout << "ok\n";
  }
}

void Solve() {
  int m;
  cin >> m;

  Minqueue stack;
  for (int i = 0; i < m; i++) {
    string command;
    cin >> command;
    HandleCommand(command, stack);
  }
}

int main() {
  Solve();
  return 0;
}
