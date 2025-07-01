#include <iostream>
#include <vector>

class DoubleHashTable {
private:
  static const int M = 11;
  std::vector<int> table;
  std::vector<bool> used;

  int Hash1(int key) {
    return key % M;
  }

  int Hash2(int key) {
    return 1 + (key % (M - 1));
  }

public:
  DoubleHashTable() : table(M, -1), used(M, false) {}

  void Insert(int key) {
    for (int i = 0; i < M; ++i) {
      int idx = (Hash1(key) + i * Hash2(key)) % M;
      if (!used[idx] || table[idx] == key) {
        table[idx] = key;
        used[idx] = true;
        return;
      }
    }
    std::cout << "Table full!\n";
  }

  bool Search(int key) {
    for (int i = 0; i < M; ++i) {
      int idx = (Hash1(key) + i * Hash2(key)) % M;
      if (!used[idx]) return false;
      if (table[idx] == key) return true;
    }
    return false;
  }

  void Erase(int key) {
    for (int i = 0; i < M; ++i) {
      int idx = (Hash1(key) + i * Hash2(key)) % M;
      if (!used[idx]) return;
      if (table[idx] == key) {
        used[idx] = false;
        table[idx] = -1;
        return;
      }
    }
  }

  void Print() {
    for (int i = 0; i < M; ++i) {
      if (used[i]) {
        std::cout << i << ": " << table[i] << "\n";
      } else {
        std::cout << i << ": EMPTY\n";
      }
    }
  }
};
