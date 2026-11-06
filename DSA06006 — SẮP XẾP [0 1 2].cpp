/*
 * PROBLEM_CODE: DSA06006
 * PROBLEM_NAME: DSA06006 — SẮP XẾP [0 1 2]
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06006
 *
 * Đề bài (Code PTIT DLab — Bài #4/42):
 * Cho mảng A[] gồm N phần tử (1 <= N <= 10^6).
 * Các phần tử của mảng A[] CHỈ bao gồm các số 0, 1, 2.
 * Hãy sắp xếp mảng A[] theo thứ tự tăng dần.
 *
 * Ví dụ Input:
 * 2
 * 5
 * 0 2 1 2 0
 * 3
 * 0 1 0
 *
 * Ví dụ Output:
 * 0 0 1 2 2
 * 0 0 1
 *
 * Thử thách chuẩn đi thi: Tự viết hàm solve() không nhìn gợi ý (thử dùng mảng đếm
 * int cnt[3] = {0}; chạy O(N) thay vì tốn RAM lưu cả mảng 10^6 phần tử!),
 * sau đó bấm Cmd + S rồi Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    // Tự code lời giải của bạn tại đây:
    int n; 
    cin >> n; 
    vector<int> a(n);
    int count[3] = {0};
    for(int i = 0; i < n; i++) {
        if(a[i] == 0 || a[i] == 1 || a[i] == 2) {
            cin >> a[i]; 
            count[a[i]]++;
        }
     }
    for(int j = 1; j <= count[0]; j++) cout << 0 << " ";
    for(int j = 1; j <= count[1]; j++) cout << 1 << " ";
    for(int j = 1; j <= count[2]; j++) cout << 2 << " ";
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
