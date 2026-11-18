/*
 * PROBLEM_CODE: DSA03004
 * PROBLEM_NAME: DSA03004 — TỔNG NHỎ NHẤT
 * Submit URL: https://code.ptit.edu.vn/submit/DSA03004
 *
 * Đề bài (Code PTIT DLab — Bài #14/42 — Phần 2: Tham lam):
 * Cho mảng A[] gồm N chữ số từ 0 đến 9 (1 <= N <= 20).
 * Hãy tạo ra 2 số nguyên sử dụng TẤT CẢ các chữ số trong mảng A[] sao cho
 * TỔNG của hai số đó là NHỎ NHẤT có thể.
 *
 * Ví dụ Input:
 * 2
 * 6
 * 6 8 4 5 2 3
 * 5
 * 5 3 0 7 4
 *
 * Ví dụ Output:
 * 604
 * 82
 * (Giải thích:
 *  - Test 1: [2,3,4,5,6,8] -> chia xen kẽ thành 246 + 358 = 604
 *  - Test 2: [0,3,4,5,7]   -> chia xen kẽ thành 047 + 35  = 82)
 *
 * ⚠️ BẪY: Vì N <= 20 nên mỗi số có thể tới 10 chữ số (> 2 tỷ), bắt buộc dùng `long long`!
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    // Tự code lời giải của bạn tại đây:
    int n; 
    cin >> n; 
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    string num1; 
    string num2;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            num1 += to_string(a[i]);
        } else {
            num2 += to_string(a[i]);
        }
    }
    cout << stoll(num1) + stoll(num2);
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
