#include <iostream>

void Merge(int* arr_l, int len_l, int* arr_r, int len_r, int* result) {
  int l = 0;
  int r = 0;
  while (l < len_l && r < len_r) {
    if (arr_l[l] <= arr_r[r]) {
      result[l + r] = arr_l[l];
      l++;
    } else {
      result[l + r] = arr_r[r];
      r++;
    }
  }
  while (l < len_l) {
    result[l + r] = arr_l[l];
    l++;
  }
  while (r < len_r) {
    result[l + r] = arr_r[r];
    r++;
  }
  for (int i = 0; i < len_l + len_r; i++) {
    arr_l[i] = result[i];
  }
}

void RecursiveMergeSort(int* arr, int len, int* buffer) {
  if (len < 2) {
    return;
  }
  int mid = len / 2;
  int* arr_l = arr;
  int len_l = mid;
  int* arr_r = arr + mid;
  int len_r = len - mid;
  RecursiveMergeSort(arr_l, len_l, buffer);
  RecursiveMergeSort(arr_r, len_r, buffer);
  Merge(arr_l, len_l, arr_r, len_r, buffer);
}

int main() {
  int len = 0;
  std::cin >> len;
  int* arr = new int[len];
  for (int i = 0; i < len; i++) {
    std::cin >> arr[i];
  }
  int* buffer = new int[len];
  RecursiveMergeSort(arr, len, buffer);
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  delete[] buffer;
  return 0;
}
