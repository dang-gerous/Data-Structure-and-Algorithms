/*
 * PROBLEM_CODE: DSA03001
 * PROBLEM_NAME: DSA03001 — ĐỔI TIỀN
 * Submit URL: https://code.ptit.edu.vn/submit/DSA03001
 *
 * Đề bài (Code PTIT DLab — Bài #11/42 — Mở màn Phần 2: Tham lam!):
 * Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000.
 * Tổng số tiền cần đổi có giá trị bằng N (1 <= N <= 100000).
 * Hãy xác định xem có ÍT NHẤT bao nhiêu tờ tiền sau khi đổi tiền?
 *
 * Ví dụ Input:
 * 2
 * 70
 * 121
 *
 * Ví dụ Output:
 * 2
 * 3
 * (Giải thích: 70 = 50 + 20 -> 2 tờ; 121 = 100 + 20 + 1 -> 3 tờ)
 *
 * Chiến lược Tham lam:
 * 1. Lưu sẵn mảng 10 mệnh giá theo thứ tự GIẢM DẦN: {1000, 500, 200, 100, 50,
 * 20, 10, 5, 2, 1}.
 * 2. Với mỗi mệnh giá c:
 *    - Cộng `n / c` vào biến đếm số tờ `ans` (lấy tối đa tờ mệnh giá lớn nhất
 * có thể!).
 *    - Cập nhật tiền còn lại: `n %= c;`
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <iostream>
using namespace std;

void solve() {
  // Tự code lời giải của bạn tại đây:
  int n;
  cin >> n;
  int i = 0;
  int c[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  int ans = 0;
  while (n > 0) {
    if (n < c[i]) {
      i++;
    } else {
      ans += n / c[i];
      n %= c[i];
      i++;
    }
  }
  cout << ans;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  if (cin >> t)
    while (t--) {
      solve();
    }
  return 0;
}
