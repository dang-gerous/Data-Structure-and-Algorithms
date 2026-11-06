/*
 * PROBLEM_CODE: DSA06010
 * PROBLEM_NAME: DSA06010 — SẮP XẾP CHỮ SỐ
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06010
 *
 * Đề bài (Code PTIT DLab — Bài #5/42):
 * Cho mảng A[] gồm N phần tử (1 <= N <= 10^7, 0 <= A[i] <= 10^16).
 * Hãy in ra tất cả các chữ số xuất hiện trong các phần tử của mảng A[]
 * theo thứ tự tăng dần (mỗi chữ số chỉ in ĐÚNG 1 LẦN).
 *
 * Ví dụ Input:
 * 2
 * 3
 * 131 11 48
 * 4
 * 111 222 333 446
 *
 * Ví dụ Output:
 * 1 3 4 8
 * 1 2 3 4 6
 *
 * Mẹo: Đọc từng phần tử bằng `string s; cin >> s;` (vừa không lo tràn số 10^16,
 * vừa không sót chữ số '0'!), kết hợp mảng đánh dấu `bool seen[10] = {false};`.
 * Tự code bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve() {
  // Tự code lời giải của bạn tại đây:
  int n;
  cin >> n;
  bool seen[10] = {false};
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
      seen[s[i] - '0'] = true;
    }
  }
  for (int i = 0; i < 10; i++) {
    if (seen[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  if (cin >> t) {
    while (t--) {
      solve();
    }
  }
  return 0;
}
