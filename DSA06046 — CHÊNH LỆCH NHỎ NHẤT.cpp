/*
 * BÀI THẬT TRÊN CODE PTIT (HỌC PHẦN DSA):
 * PROBLEM_CODE: DSA06046
 * PROBLEM_NAME: DSA06046 — CHÊNH LỆCH NHỎ NHẤT
 * Link trên Code PTIT: https://code.ptit.edu.vn/student/question/DSA06046
 *
 * Đề bài gốc Code PTIT:
 * Cho mảng A[] gồm N phần tử (1 <= N <= 10^5, 0 <= A[i] <= 10^9).
 * Hãy tìm hiệu nhỏ nhất (chênh lệch nhỏ nhất) giữa hai phần tử bất kỳ trong dãy số!
 * (Chính là bài bạn vừa code xong, chỉ khác duy nhất dòng cout cuối: chỉ in ra `best`, KHÔNG in `cnt`!)
 *
 * Input mẫu Code PTIT:
 * 2
 * 6
 * 1 5 3 19 18 25
 * 4
 * 30 5 20 9
 *
 * Output mẫu Code PTIT:
 * 1
 * 4
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long best = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        long long d = a[i + 1] - a[i];
        if (d < best) {
            best = d;
        }
    }
    cout << best << "\n";
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
