#include <iostream>
#include <iomanip>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  int* n_array = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> n_array[i];
  }
  int* k_array = new int[k];
  for (int i = 0; i < k; ++i) {
    std::cin >> k_array[i];
  }
  for (int i = 0; i < k; i++) {
    int key = k_array[i];
    int left = 0;
    int right = n - 1;
    bool found = false;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (n_array[mid] == key) {
        found = true;
        break;
      }
      if (n_array[mid] < key) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    std::cout << (found ? "YES\n" : "NO\n");
  }
  delete[] n_array;
  delete[] k_array;
  return 0;
}
