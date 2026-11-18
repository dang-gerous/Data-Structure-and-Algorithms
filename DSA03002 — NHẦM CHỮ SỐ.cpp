/*
 * PROBLEM_CODE: DSA03002
 * PROBLEM_NAME: DSA03002 — NHẦM CHỮ SỐ
 * Submit URL: https://code.ptit.edu.vn/submit/DSA03002
 *
 * Đề bài (Code PTIT DLab — Bài #12/42 — Phần 2: Tham lam):
 * Trong một buổi học toán, giáo viên viết 2 số nguyên dương A và B lên bảng.
 * Tèo rất hay nhìn nhầm chữ số '5' thành '6' và ngược lại ('6' thành '5').
 * Cho hai số nguyên dương A và B (1 <= A, B <= 10^6).
 * Hãy tính tổng NHỎ NHẤT và tổng LỚN NHẤT có thể mà Tèo tính được!
 * (Chú ý: Bài này KHÔNG có số bộ test T ở đầu, chỉ có 1 dòng chứa A và B!)
 *
 * Ví dụ Input:
 * 11 25
 *
 * Ví dụ Output:
 * 36 37
 * (Giải thích: Nhỏ nhất khi đổi '6'->'5': 11 + 25 = 36; Lớn nhất khi đổi '5'->'6': 11 + 26 = 37)
 *
 * Ví dụ 2:
 * 16796 58786  -->  Nhỏ nhất: 15795 + 58785 = 74580; Lớn nhất: 16796 + 68786 = 85582
 *
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <iostream>
#include <string>
using namespace std;

long long tomax(string s) {
  for(auto &x : s) {
    if(x  == '5') {
       x = '6';
    }
  }
  return stoll(s);
}

long long tomin(string s) {
  for(auto &x : s) {
    if(x  == '6') {
       x = '5';
    }
  }
  return stoll(s);
}
void solve() {
  // Tự code lời giải của bạn tại đây:
  string a,b; 
  cin >> a >> b;
  cout << tomin(a) + tomin(b) << " " << tomax(a) + tomax(b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
