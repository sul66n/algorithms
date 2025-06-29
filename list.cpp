#include <iostream> 
#include <cstring> 
 
struct Node { 
  int val; 
  Node* next = nullptr; 
}; 
 
struct List { 
  Node* head = nullptr; 
  Node* tail = nullptr; 
  size_t size = 0; 
  bool IsEmpty() { 
    return head == nullptr; 
  } 
  void PushBack(int value) { 
    Node* new_node = new Node{value}; 
    if (IsEmpty()) { 
      head = new_node; 
      tail = new_node; 
      return; 
    } 
    tail->next = new_node; 
    tail = new_node; 
  } 
  void PushFront(int value) { 
    Node* new_node = new Node{value}; 
    if (IsEmpty()) { 
      head = tail = new_node; 
    } else { 
      new_node->next = head; 
      head = new_node; 
    } 
  } 
  void PopHead() { 
    if (IsEmpty()) { 
      return; 
    } 
    Node* temp = head->next; 
    delete head; 
    head = temp; 
    if (head == nullptr) { 
      tail = nullptr; 
    } 
  } 
  void PopTail() { 
    if (IsEmpty()) { 
      return; 
    } 
    if (head == tail) { 
      delete head; 
      head = tail = nullptr; 
    } else { 
      Node* runner = head; 
      while (runner->next->next != nullptr) { 
        runner = runner->next; 
      } 
      delete runner->next; 
      tail = runner; 
      runner->next = nullptr; 
    } 
  } 
  int Size() { 
    Node* runner = head; 
    int count = 0; 
    while (runner != nullptr) { 
      count++; 
      runner = runner->next; 
    } 
    return count; 
  } 
  int operator[] (int index) { 
    Node* runner = head; 
    for (int i = 0; i < index; i++) { 
      runner = runner->next; 
    } 
    return runner->val; 
  } 
  void Print() { 
  Node* runner = head; 
  while (runner) { 
    std::cout << runner->val << " "; 
    runner = runner->next; 
  } 
  std::cout << '\n'; 
  } 
}; 
 
int main() { 
  List list; 
  list.PushBack(2); 
  list.PushFront(3); 
  list.PopTail(); 
  list.Print(); 
  std::cout << list[0] << '\n'; 
  std::cout << list.Size(); 
  return 0; 
}
