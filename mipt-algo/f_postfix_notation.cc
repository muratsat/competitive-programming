#include <cctype>
#include <iostream>

using namespace std;

static const int kMaxStackSize = 100000;

struct Stack {
  int Push(int n);
  int Pop();
  int Top();

 private:
  int item_[kMaxStackSize];
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

static int Operate(int a, int b, char op) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
  }
  return 0;
}

void Solve() {
  Stack stack;
  char term;

  while (cin >> term) {
    if (isdigit(term) != 0) {
      stack.Push(term - '0');
    } else {
      int a = stack.Top();
      stack.Pop();
      int b = stack.Top();
      stack.Pop();
      stack.Push(Operate(b, a, term));
    }
  }

  cout << stack.Top() << '\n';
}

int main() {
  Solve();
  return 0;
}