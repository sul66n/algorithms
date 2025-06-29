#include <iostream>
#include <cstring>

struct Node {
  int val;
  Node* next = nullptr;
};

struct Stack {
  Node* head = nullptr;
  size_t size = 0;
  bool IsEmpty() {
    return head == nullptr;
  }
  void Push(int value) {
    Node* new_node = new Node{value};
    new_node->val = value;
    new_node->next = head;
    head = new_node;
    size++;
  }
  void Pop() {
    if (IsEmpty()) {
      return;
    }
    Node* temp = head->next;
    delete head;
    head = temp;
    size--;
  }
  void Back() {
    std::cout << head->val << '\n';
  }
  void Clear() {
    while (!IsEmpty()) {
      Pop();
    }
  }
  int Size() {
    int count = 0;
    Node* runner = head;
    while (runner != nullptr) {
      count++;
      runner = runner->next;
    }
    return count;
  }
};

int main() {
  char command[6];
  Stack stack;
  while (true) {
    std::cin >> command;
    if (!strcmp(command, "push")) {
      int n = 0;
      std::cin >> n;
      stack.Push(n);
      std::cout << "ok\n";
    } else if (!strcmp(command, "pop")) {
      stack.Back();
      stack.Pop();
    } else if (!strcmp(command, "back")) {
      stack.Back();
    } else if (!strcmp(command, "size")) {
      std::cout << stack.size << '\n';
    } else if (!strcmp(command, "clear")) {
      stack.Clear();
      std::cout << "ok\n";
    } else if (!strcmp(command, "exit")) {
      std::cout << "bye\n";
      stack.Clear();
      return 0;
    }
  }
}
