/*
 * PROBLEM_CODE: DSA06002
 * PROBLEM_NAME: DSA06002 — SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06002
 *
 * Đề bài (Code PTIT DLab — Bài #3/42):
 * Cho mảng A[] gồm N phần tử và số X (1 <= N, X, A[i] <= 10^5).
 * Hãy sắp xếp các phần tử của mảng theo trị tuyệt đối |X - A[i]| tăng dần.
 * ⚠️ QUAN TRỌNG: Nếu 2 phần tử có cùng |X - A[i]|, giữ nguyên thứ tự xuất hiện
 * ban đầu!
 *
 * Ví dụ Input:
 * 2
 * 5 7
 * 10 5 3 9 2
 * 5 6
 * 1 2 3 4 5
 *
 * Ví dụ Output:
 * 5 9 10 3 2
 * 5 4 3 2 1
 *
 * Gợi ý: Tự code bên dưới (dùng stable_sort + hàm so sánh/lambda + #include
 * <cmath> cho abs), sau đó bấm Cmd + S rồi Cmd + Shift + B!
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stable_sort(a.begin(), a.end(), [x](int u, int v) { return abs(x - u) < abs(x - v); });
  // 1. Nhập n và x
  // 2. Nhập vector<int> a(n)
  // 3. Dùng stable_sort(a.begin(), a.end(), [x](int u, int v) { ... });
  //    So sánh: abs(x - u) < abs(x - v)
  // 4. In mảng a cách nhau dấu cách, kết thúc bằng "\n"
  for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
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
