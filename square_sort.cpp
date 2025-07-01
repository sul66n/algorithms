#include <iostream>

void Input(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
}

void Print(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}

void Swap(int& lns, int& rns) {
  int tmp = lns;
  lns = rns;
  rns = tmp;
}

void SelectionSort(int* arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    int ind_min = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[ind_min]) {
        ind_min = j;
      }
    }
    if (ind_min != i) {
      Swap(arr[i], arr[ind_min]);
    }
  }
}

void InsertionSort(int* arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    int j = i + 1;
    while ((j > 0) && (arr[j] < arr[j - 1])) {
      Swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}

void BubbleSort(int* arr, const int size) {
  for (int i = 0; i < size - 1; i++) {
    bool flag = false;
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        Swap(arr[j], arr[j + 1]);
        flag = true;
      }
    }
    if (!flag) {
      return;
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  int* arr = new int[n];
  Input(arr, n);
  SelectionSort(arr, n);
  Print(arr, n);
  delete[] arr;
  return 0;
}
