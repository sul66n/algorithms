#include <iostream>

bool BinarySearch(int* arr, int value, int size) {
  int right = size - 1;
  int left = 0;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] > value) {
      right = mid - 1;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  int value = 0;
  std::cin >> value;
  int arr[] = {1, 3, 4, 5, 7, 9};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << (BinarySearch(arr, value, size) ? "YES" : "NO");
  return 0;
}
