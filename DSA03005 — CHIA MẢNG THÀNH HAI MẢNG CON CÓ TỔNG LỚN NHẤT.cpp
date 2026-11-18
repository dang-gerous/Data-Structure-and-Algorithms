/*
 * PROBLEM_CODE: DSA03005
 * PROBLEM_NAME: DSA03005 — CHIA MẢNG THÀNH HAI MẢNG CON CÓ TỔNG LỚN NHẤT
 * Submit URL: https://code.ptit.edu.vn/submit/DSA03005
 *
 * Đề bài (Code PTIT DLab — Bài #15/42 — Phần 2: Tham lam):
 * Cho mảng A[] gồm N số nguyên không âm và số K (1 <= K < N <= 50).
 * Hãy chia mảng A[] thành hai mảng con có kích thước K và N - K sao cho
 * HIỆU giữa tổng các phần tử của hai mảng con đó là LỚN NHẤT.
 *
 * Ví dụ Input:
 * 2
 * 5 2
 * 8 4 5 2 10
 * 8 3
 * 1 1 1 1 1 1 1 1
 *
 * Ví dụ Output:
 * 17
 * 2
 * (Giải thích test 1: xếp [2, 4, 5, 8, 10] -> nhóm 2 số nhỏ (2+4=6) và nhóm 3 số lớn (5+8+10=23) -> |23 - 6| = 17)
 *
 * ⚠️ BẪY K > N - K: Nếu đề cho N = 5, K = 4, ta chỉ gom `m = min(k, n - k)` phần tử
 * NHỎ NHẤT vào một nhóm, nhóm còn lại lấy toàn bộ phần tử LỚN NHẤT!
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    // Tự code lời giải của bạn tại đây:
    int n,k; 
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int g1 = 0; 
    int g2 = 0; 
    if (k > n - k) {
    for(int i = 1; i <= n; i++) {
        if(i <= n - k) {
            g1 += a[i];
        } else {
        g2 += a[i];
        }
    }
    } else {
    for(int i = 1; i <= n; i++) {
        if(i <= k) {
            g1 += a[i];
        } else {
        g2 += a[i];
        }
    }
    }
cout << abs(g2 - g1); 
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
