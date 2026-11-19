/*
 * PROBLEM_CODE: DSA03008
 * PROBLEM_NAME: DSA03008 — SẮP XẾP CÔNG VIỆC 1
 * Submit URL: https://code.ptit.edu.vn/submit/DSA03008
 *
 * Đề bài (Code PTIT DLab — Bài #16/42 — Trùm cuối Phần 2: Tham lam!):
 * Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như một bộ đôi <S[i], F[i]>,
 * trong đó S[i] là thời gian bắt đầu và F[i] là thời gian kết thúc của hành động thứ i.
 * (Chú ý định dạng Input: dòng 1 nhập N, dòng 2 nhập cả N số S[i], dòng 3 nhập cả N số F[i]).
 * Hãy tìm số lượng hành động NHIỀU NHẤT có thể thực hiện được sao cho không bị trùng giờ
 * (hành động sau được chọn khi S[j] >= F[i] của hành động trước đó).
 *
 * Ví dụ Input:
 * 1
 * 6
 * 1 3 0 5 8 5
 * 2 4 6 7 9 9
 *
 * Ví dụ Output:
 * 4
 * (Giải thích: Chọn được tối đa 4 việc: (1,2) -> (3,4) -> (5,7) -> (8,9))
 *
 * Chiến lược Tham lam Kinh điển (Activity Selection):
 * 1. Gom thành `vector<pair<int, int>> a(n)` với `a[i].first = S[i]`, `a[i].second = F[i]`.
 * 2. Sắp xếp theo **THỜI GIAN KẾT THÚC `second` TĂNG DẦN**!
 * 3. Chọn việc đầu tiên (`ans = 1, last_end = a[0].second`), rồi duyệt các việc tiếp theo:
 *    nếu `a[i].first >= last_end` thì `ans++` và cập nhật `last_end = a[i].second`!
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
bool comp(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}
void solve() {
    // Tự code lời giải của bạn tại đây:
    int n; 
    cin >> n; 
    vector<pair <int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
       for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end(), comp);
    int ans = 1; 
    int last_end = a[0].second;
    for(int i = 1; i < n; i++) {
        if(a[i].first >= last_end) {
            last_end = a[i].second;
            ans++;
        }
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
