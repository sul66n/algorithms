#include <iostream>

int PartitionLomuto(int* arr, int left, int right) {
  int p = arr[right];
  int i = left;
  for (int j = left; j < right; j++) {
    if (arr[j] <= p) {
      std::swap(arr[i], arr[j]);
      i++;
    }
  }
  std::swap(arr[i], arr[right]);
  return i;
}

int PartitionHoare(int* arr, int left, int right) {
  int pivot = arr[(right + left) / 2];
  int l = left;
  int r = right;
  while (true) {
    while (arr[l] < pivot) {
      l++;
    }
    while (arr[r] > pivot) {
      r--;
    }
    if (l >= r) {
      return r;
    }
    std::swap(arr[l++], arr[r--]);
  }
}

void QuickSortLomuto(int* arr, int left, int right) {
  if (left < right) {
    int id_pivot = PartitionLomuto(arr, left, right);
    QuickSortLomuto(arr, left, id_pivot - 1);
    QuickSortLomuto(arr, id_pivot + 1, right);
  }
}

void QuickSortHoare(int* arr, int left, int right) {
  if (left < right) {
    int id_pivot = PartitionHoare(arr, left, right);
    QuickSortHoare(arr, left, id_pivot);
    QuickSortHoare(arr, id_pivot + 1, right);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  QuickSortHoare(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}
