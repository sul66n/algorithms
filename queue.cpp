#include <iostream>
#include <cstring>

struct Node {
  int val;
  Node* next = nullptr;
};

struct Queue {
  Node* head = nullptr;
  Node* tail = nullptr;
  size_t size = 0;
  bool IsEmpty() {
    return head == nullptr;
  }
  void Push(int value) {
    Node* new_node = new Node{value};
    if (IsEmpty()) {
      head = new_node;
      tail = new_node;
      size++;
      return;
    }
    tail->next = new_node;
    tail = new_node;
    size++;
  }
  void Pop() {
    if (IsEmpty()) {
      return;
    }
    Node* temp = head->next;
    delete head;
    head = temp;
    if (head == nullptr) {
      tail = nullptr;
    }
    size--;
  }
  void Front() {
    std::cout << head->val << '\n';
  }
  void Clear() {
    while (!IsEmpty()) {
      Pop();
    }
  }
};

int main() {
  char command[6];
  Queue queue;
  while (true) {
    std::cin >> command;
    if (!strcmp(command, "push")) {
      int n = 0;
      std::cin >> n;
      queue.Push(n);
      std::cout << "ok\n";
    } else if (!strcmp(command, "pop")) {
      queue.Front();
      queue.Pop();
    } else if (!strcmp(command, "front")) {
      queue.Front();
    } else if (!strcmp(command, "size")) {
      std::cout << queue.size << '\n';
    } else if (!strcmp(command, "clear")) {
      queue.Clear();
      std::cout << "ok\n";
    } else if (!strcmp(command, "exit")) {
      std::cout << "bye\n";
      queue.Clear();
      return 0;
    }
  }
}
