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
}

int main() {
  int n1 = 0;
  std::cin >> n1;
  int* arr1 = new int[n1];
  for (int i = 0; i < n1; i++) {
    std::cin >> arr1[i];
  }
  int n2 = 0;
  std::cin >> n2;
  int* arr2 = new int[n2];
  for (int i = 0; i < n2; i++) {
    std::cin >> arr2[i];
  }
  int* buffer = new int[n1 + n2];
  Merge(arr1, n1, arr2, n2, buffer);
  for (int i = 0; i < n1 + n2; i++) {
    std::cout << buffer[i] << " ";
  }
  delete[] arr1;
  delete[] arr2;
  delete[] buffer;
  return 0;
}
