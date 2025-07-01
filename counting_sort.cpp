#include <iostream>

void CountingSort(int* arr, const int size, int max) {
  int* m = new int[max];
  for (int i = 0; i < max; i++) {
    m[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    m[arr[i]]++;
  }
  int pos = 0;
  for (int i = 0; i < max; i++) {
    while (m[i] > 0) {
      arr[pos] = i;
      pos++;
      m[i]--;
    }
  }
  delete[] m;
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  CountingSort(arr, n, 100000);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}
