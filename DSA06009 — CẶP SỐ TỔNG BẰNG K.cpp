/*
 * PROBLEM_CODE: DSA06009
 * PROBLEM_NAME: DSA06009 — CẶP SỐ TỔNG BẰNG K
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06009
 *
 * Đề bài (Code PTIT DLab — Bài #7/42):
 * Cho mảng A[] gồm N phần tử và số nguyên K.
 * Hãy đếm tất cả các cặp chỉ số (i, j) sao cho i < j và A[i] + A[j] == K.
 *
 * Ví dụ Input:
 * 2
 * 5 9
 * 1 5 4 1 2
 * 3 2
 * 1 1 1
 *
 * Ví dụ Output:
 * 1
 * 3
 *
 * Vũ khí chuẩn đi thi (chấp cả đề N = 10^5 không sợ TLE!):
 * 1. Sắp xếp mảng tăng dần: sort(a.begin(), a.end());
 * 2. Dùng `long long ans = 0;` (tránh tràn int khi có hàng tỷ cặp trùng nhau!).
 * 3. Duyệt i từ 0 đến n - 1, cần tìm `need = k - a[i]` trong đoạn bên phải
 * `a.begin() + i + 1` đến `a.end()`: auto l = lower_bound(a.begin() + i + 1,
 * a.end(), need); auto r = upper_bound(a.begin() + i + 1, a.end(), need); ans
 * += (r - l); Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  // Tự code lời giải của bạn tại đây:
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int need = k - a[i];
    auto l = lower_bound(a.begin() + i + 1, a.end(), need);
    auto r = upper_bound(a.begin() + i + 1, a.end(), need);
    ans += (r - l);
  }
  cout << ans;
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
