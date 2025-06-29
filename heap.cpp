#include <iostream>

int64_t LeftChild(int64_t i) {
  return 2 * i + 1;
}

int64_t RightChild(int64_t i) {
  return 2 * i + 2;
}

int64_t Parent(int64_t i) {
  return (i - 1) / 2;
}

template <class T>
void SiftDown(T* arr, int64_t len, int64_t i) {
  while (i < len) {
    int64_t max = i;
    int64_t ch1 = LeftChild(i);
    int64_t ch2 = RightChild(i);
    if (ch1 < len && arr[ch1] > arr[max]) {
      max = ch1;
    }
    if (ch2 < len && arr[ch2] > arr[max]) {
      max = ch2;
    }
    if (max == i) {
      break;
    } else {
      std::swap(arr[max], arr[i]);
      i = max;
    }
  }
}

template <class T>
void Heapify(T* arr, int64_t len) {
  for (int i = len / 2 - 1; i != -1; i--) {
    SiftDown(arr, len, i);
  }
}

template <class T>
void HeapSort(T* arr, int64_t len) {
  Heapify(arr, len);
  
  for (int64_t i = len - 1; i != 0; i--) {
    std::swap(arr[0], arr[i]);
    SiftDown(arr, i, 0);
  }
}

int main() {
  int64_t n = 0;
  std::cin >> n;
  auto* arr = new int64_t[n];
  for (int64_t i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  HeapSort(arr, n);
  for (int64_t i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  delete[] arr;
  return 0;
}
