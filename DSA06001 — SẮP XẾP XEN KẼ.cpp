/*
 * PROBLEM_CODE: DSA06001
 * PROBLEM_NAME: DSA06001 — SẮP XẾP XEN KẼ
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06001
 *
 * Đề bài (Code PTIT DLab):
 * Cho mảng A[] gồm N số nguyên khác nhau (1 <= N <= 1000).
 * Hãy in ra các phần tử theo khuôn dạng xen kẽ:
 *   lớn nhất, nhỏ nhất, lớn thứ hai, nhỏ thứ hai, ...
 *
 * Ví dụ Input:
 * 2
 * 7
 * 7 1 2 3 4 5 6
 * 6
 * 9 7 12 8 6 5
 *
 * Ví dụ Output:
 * 7 1 6 2 5 3 4
 * 12 5 9 6 8 7
 *
 * Lưu ý: Tự code từ đầu bên dưới (đừng mở xem file cũ!), sau đó bấm Cmd + S rồi
 * Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    if (a[l] == a[r]) {
      cout << a[l];
      break;
    } else {
      cout << a[r] << " " << a[l] << " ";
      r--;
      l++;
    }
  }
  cout << "\n";
  // 1. Sắp xếp vector 'a' tăng dần bằng sort(...)
  // 2. Tạo 2 con trỏ: int l = 0, r = n - 1;
  // 3. Dùng vòng lặp while (l <= r):
  //      - Nếu l == r thì chỉ in a[l] 1 lần!
  //      - Ngược lại thì in a[r] trước (lớn), rồi a[l] sau (nhỏ)!
  //      - Tăng l++, giảm r--
  // 4. Nhớ cout << "\n"; khi hết 1 bộ test!
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
