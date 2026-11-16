/*
 * PROBLEM_CODE: DSA06015
 * PROBLEM_NAME: DSA06015 — MERGE SORT
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06015
 *
 * Đề bài (Code PTIT DLab — Bài #10/42 — Trùm cuối Phần 1: Sắp xếp!):
 * Cho mảng A[] gồm N phần tử chưa được sắp xếp (1 <= N <= 10^6, 1 <= A[i] <=
 * 10^6). Hãy sắp xếp các phần tử của mảng A[] theo thứ tự tăng dần bằng thuật
 * toán Merge Sort trong thời gian O(N log N).
 *
 * Ví dụ Input:
 * 2
 * 5
 * 4 1 3 9 7
 * 10
 * 10 9 8 7 6 5 4 3 2 1
 *
 * Ví dụ Output:
 * 1 3 4 7 9
 * 1 2 3 4 5 6 7 8 9 10
 *
 * Thử thách hoàn tất 10/10 bài Phần 1:
 * Hãy tự viết hàm `merge(vector<int>& a, int l, int m, int r)` (dùng đúng 2 con
 * trỏ trộn 2 mảng con L và R như bài #8!) và hàm đệ quy `mergeSort(vector<int>&
 * a, int l, int r)`. Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift +
 * B!
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int m, int r) {
  // 1. Tạo 2 vector phụ:
  //    vector<int> L(a.begin() + l, a.begin() + m + 1);
  //    vector<int> R(a.begin() + m + 1, a.begin() + r + 1);
  // 2. Dùng 2 con trỏ i = 0, j = 0 và k = l để trộn L, R đè ngược vào a[k++]!
  vector<int> L(a.begin() + l, a.begin() + m + 1);
  vector<int> R(a.begin() + m + 1, a.begin() + r + 1);
  int i = 0, j = 0, k = l; // k bắt đầu từ l trên mảng a!

  while (i < L.size() && j < R.size()) {
    if (L[i] <= R[j]) {
      a[k++] = L[i++]; // lấy từ L nhét vào a
    } else {
      a[k++] = R[j++]; // lấy từ R nhét vào a
    }
  }
  // Vét nốt phần thừa (nếu có):
  while (i < L.size())
    a[k++] = L[i++];
  while (j < R.size())
    a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int l, int r) {
  // Điều kiện dừng: if (l >= r) return;
  // Chia đôi: int m = l + (r - l) / 2;
  // Gọi đệ quy 2 nửa rồi gọi merge(a, l, m, r);
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  mergeSort(a, l, m);     // 1. Tự sắp xếp nửa trái [l .. m]
  mergeSort(a, m + 1, r); // 2. Tự sắp xếp nửa phải [m+1 .. r]
  merge(a, l, m, r);      // 3. Trộn 2 nửa đã xếp lại vào a
}

void solve() {
  // Nhập n, mảng a, gọi mergeSort(a, 0, n - 1) rồi in kết quả:
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  mergeSort(a, 0, n - 1);
  for (auto x : a)
    cout << x << " ";
    cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}
