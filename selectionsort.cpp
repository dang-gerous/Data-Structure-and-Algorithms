#include <iostream>
using namespace std;

void selectionsort(int A[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      swap(A[i], A[min_idx]);
    }
  }
}
int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
        cin >> A[i
  };
  selectionsort(A, n);
}
