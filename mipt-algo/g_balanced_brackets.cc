#include <iostream>

using namespace std;

static const int kMaxStackSize = 100000;

struct Stack {
  int Push(int n);
  int Pop();
  int Top();

 private:
  char item_[kMaxStackSize];
  int size_ = 0;
};

int Stack::Push(int n) {
  item_[size_] = n;
  size_++;
  return 0;
}

int Stack::Pop() {
  if (size_ == 0) {
    return -1;
  }
  size_--;
  return item_[size_];
}

int Stack::Top() {
  if (size_ == 0) {
    return -1;
  }
  return item_[size_ - 1];
}

static bool IsOpen(char c) { return c == '(' || c == '[' || c == '{'; }

static bool IsMatch(char open, char close) {
  return (open == '(' && close == ')') || (open == '[' && close == ']') ||
         (open == '{' && close == '}');
}

void Solve() {
  Stack stack;
  char brace;
  bool balanced = true;

  while (cin >> brace) {
    if (IsOpen(brace)) {
      stack.Push(brace);
    } else {
      char last = stack.Top();
      if (IsMatch(last, brace)) {
        stack.Pop();
      } else {
        if (IsMatch(last, brace)) {
          stack.Pop();
        } else {
          balanced = false;
        }
      }
    }
  }

  if (balanced && stack.Top() == -1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}

int main() {
  Solve();
  return 0;
}