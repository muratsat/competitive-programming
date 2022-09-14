#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Pair {
  int first, second;
};

static const int kMaxStackSize = 200000;

struct MinStack {
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

int MinStack::Push(int n) {
  item_[size_].first = n;
  int min = n;
  if (size_ > 0 && item_[size_ - 1].second < min) {
    min = item_[size_ - 1].second;
  }
  item_[size_].second = min;
  size_++;
  return 0;
}

int MinStack::Pop() {
  if (size_ == 0) {
    return -1;
  }
  size_--;
  return item_[size_].first;
}

int MinStack::Back() {
  if (size_ == 0) {
    return -1;
  }
  return item_[size_ - 1].first;
}

int MinStack::Min() {
  if (size_ == 0) {
    return -1;
  }
  return item_[size_ - 1].second;
}

int MinStack::Size() { return size_; }

int MinStack::Clear() {
  size_ = 0;
  return 0;
}

struct MinQueue {
  int Enqueue(int n);
  int Dequeue();
  int Front();
  int Size();
  int Clear();
  int Min();

 private:
  MinStack stack1_, stack2_;
};

int MinQueue::Enqueue(int n) {
  stack1_.Push(n);
  return 0;
}

int MinQueue::Dequeue() {
  if (stack2_.Size() == 0) {
    while (stack1_.Size() != 0) {
      stack2_.Push(stack1_.Pop());
    }
  }
  return stack2_.Pop();
}

int MinQueue::Front() {
  if (stack2_.Size() == 0) {
    while (stack1_.Size() > 0) {
      stack2_.Push(stack1_.Pop());
    }
  }
  return stack2_.Back();
}

int MinQueue::Size() { return stack1_.Size() + stack2_.Size(); }

int MinQueue::Clear() {
  stack1_.Clear();
  stack2_.Clear();
  return 0;
}

int MinQueue::Min() {
  int m1 = stack1_.Min(), m2 = stack2_.Min();
  if (m1 == -1) {
    return m2;
  }
  if (m2 == -1) {
    return m1;
  }
  return min(m1, m2);
}

static void HandleError(int result) {
  if (result == -1) {
    cout << "error\n";
  } else {
    cout << result << '\n';
  }
}

static void HandleCommand(string command, MinQueue& queue) {
  if (command == "enqueue") {
    int n;
    cin >> n;
    queue.Enqueue(n);
    cout << "ok\n";
  } else if (command == "dequeue") {
    HandleError(queue.Dequeue());
  } else if (command == "front") {
    HandleError(queue.Front());
  } else if (command == "size") {
    cout << queue.Size() << '\n';
  } else if (command == "clear") {
    queue.Clear();
    cout << "ok\n";
  } else if (command == "min") {
    HandleError(queue.Min());
  }
}

void Solve() {
  int m;
  cin >> m;

  MinQueue queue;
  for (int i = 0; i < m; i++) {
    string command;
    cin >> command;
    HandleCommand(command, queue);
  }
}

int main() {
  Solve();
  return 0;
}
