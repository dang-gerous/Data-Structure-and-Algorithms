/*
 * PROBLEM_CODE: DSA06044
 * PROBLEM_NAME: DSA06044 — SẮP XẾP CHẴN LẺ
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06044
 *
 * Đề bài (Code PTIT DLab — Bài #9/42):
 * Cho dãy số a[] có n phần tử, đánh số thứ tự từ 1 đến n (1 <= n <= 10^5).
 * Hãy sắp xếp:
 *   - Các phần tử ở VỊ TRÍ LẺ (1, 3, 5...) theo thứ tự TĂNG DẦN.
 *   - Các phần tử ở VỊ TRÍ CHẴN (2, 4, 6...) theo thứ tự GIẢM DẦN.
 *
 * ⚠️ 2 BẪY CHẾT NGƯỜI CỦA ĐỀ NÀY:
 * 1) Đề KHÔNG CÓ số bộ test T ở đầu! Chỉ đọc 1 lần `n` rồi đọc `n` số!
 * 2) Chia theo VỊ TRÍ (thứ tự 1..n) chẵn/lẻ, KHÔNG phải chia theo giá trị
 * chẵn/lẻ! Mẹo không bao giờ nhầm: Duyệt `for (int i = 1; i <= n; i++)`!
 *
 * Ví dụ Input:
 * 4
 * 1 2 3 4
 *
 * Ví dụ Output:
 * 1 4 3 2
 *
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  // Tự code lời giải của bạn tại đây:
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> chan;
  vector<int> le;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      le.push_back(a[i]);
    } else {
      chan.push_back(a[i]);
    }
  }
  sort(le.begin(), le.end());
  sort(chan.begin(), chan.end(), greater<int>());
  int ple = 0, pchan = 0;
  for(int i = 1; i <= n; i++) {
    if(i % 2 != 0) {
        cout << le[ple++] << " ";
    } else {
        cout << chan[pchan++] << " ";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // Chú ý: Bài này trên Code PTIT chỉ có 1 test duy nhất (không có T)!
  solve();
  return 0;
}
