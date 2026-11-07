/*
 * PROBLEM_CODE: DSA06022
 * PROBLEM_NAME: DSA06022 — SỐ NHỎ NHẤT VÀ NHỎ THỨ HAI
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06022
 *
 * Đề bài (Code PTIT DLab — Bài #6/42):
 * Cho mảng A[] gồm N phần tử (2 <= N <= 10^7, 1 <= A[i] <= 10^7).
 * Hãy in ra số nhỏ nhất và số nhỏ thứ hai (KHÁC số nhỏ nhất) của mảng.
 * Nếu không tồn tại số nhỏ thứ hai (tất cả phần tử bằng nhau), in ra -1.
 *
 * Ví dụ Input:
 * 2
 * 10
 * 5 6 7 8 9 10 1 2 3 4
 * 5
 * 1 1 1 1 1
 *
 * Ví dụ Output:
 * 1 2
 * -1
 *
 * Thử thách: Với N lên tới 10^7, hãy thử giữ 2 biến kỷ lục `min1 = INT_MAX,
 * min2 = INT_MAX` và duyệt đúng 1 vòng O(N) không cần lưu mảng! Bấm Cmd + S ->
 * Cmd + Shift + B!
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  // Tự code lời giải của bạn tại đây:
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int min1 = INT_MAX;
  int min2 = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (a[i] < min1) {
      min2 = min1;
      min1 = a[i];
    } else if (a[i] < min2 && a[i] != min1)
      min2 = a[i];
  }

  if (min2 == INT_MAX) {
    cout << "-1";
  } else {
    cout << min1 << " " << min2;
  }
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
