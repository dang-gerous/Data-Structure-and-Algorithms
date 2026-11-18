/*
 * PROBLEM_CODE: DSA03003
 * PROBLEM_NAME: DSA03003 — TÌM MAX
 * Submit URL: https://code.ptit.edu.vn/submit/DSA03003
 *
 * Đề bài (Code PTIT DLab — Bài #13/42 — Phần 2: Tham lam):
 * Cho mảng A[] gồm N phần tử (1 <= N <= 10^7).
 * Hãy tìm giá trị LỚN NHẤT của tổng:
 *     Sum = A[0]*0 + A[1]*1 + A[2]*2 + ... + A[N-1]*(N-1)
 * bằng cách sắp đặt lại các phần tử trong mảng A[].
 * Vì kết quả có thể rất lớn, hãy in ra phần dư của tổng khi chia cho (10^9 + 7).
 *
 * Ví dụ Input:
 * 2
 * 5
 * 5 3 2 4 1
 * 3
 * 1 2 3
 *
 * Ví dụ Output:
 * 40
 * 8
 * (Giải thích test 1: xếp thành [1, 2, 3, 4, 5] -> 1*0 + 2*1 + 3*2 + 4*3 + 5*4 = 40)
 *
 * ⚠️ BẪY TRÀN SỐ: Nhớ dùng `const long long MOD = 1e9 + 7;` và ép kiểu `1LL * a[i] * i`!
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
    // Tự code lời giải của bạn tại đây:
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i]*i;
    }
    cout << ans % MOD; 
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
