#include <iostream>
#include <vector>
#include <list>

class HashTable {
private:
  static const int M = 10; // размер таблицы
  std::vector<std::list<int>> table;

  int Hash(int key) {
    return key % M;
  }

public:
  HashTable() : table(M) {}

  void Insert(int key) {
    int h = Hash(key);
    for (int k : table[h]) {
      if (k == key) return; // уже есть
    }
    table[h].push_back(key);
  }

  bool Search(int key) {
    int h = Hash(key);
    for (int k : table[h]) {
      if (k == key) return true;
    }
    return false;
  }

  void Erase(int key) {
    int h = Hash(key);
    table[h].remove(key);
  }

  void Print() {
    for (int i = 0; i < M; ++i) {
      std::cout << i << ": ";
      for (int k : table[i]) {
        std::cout << k << " ";
      }
      std::cout << '\n';
    }
  }
};
