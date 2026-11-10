/*
 * PROBLEM_CODE: DSA06004
 * PROBLEM_NAME: DSA06004 — HỢP VÀ GIAO CỦA HAI DÃY SỐ 1
 * Submit URL: https://code.ptit.edu.vn/submit/DSA06004
 *
 * Đề bài (Code PTIT DLab — Bài #8/42):
 * Cho mảng A[] gồm N phần tử và mảng B[] gồm M phần tử đôi một khác nhau,
 * đã được sắp xếp tăng dần (1 <= N, M <= 10^5).
 * Hãy in ra dòng 1 là mảng Hợp (Union) và dòng 2 là mảng Giao (Intersection)
 * của hai dãy số theo thứ tự tăng dần.
 *
 * Ví dụ Input:
 * 1
 * 5 3
 * 1 2 3 4 5
 * 1 2 3
 *
 * Ví dụ Output:
 * 1 2 3 4 5
 * 1 2 3
 *
 * Kỹ thuật 2 Con Trỏ Trộn Dãy (bước đệm trực tiếp cho bài #10 Merge Sort!):
 * - Đặt i = 0 (trên A), j = 0 (trên B).
 * - Khi i < n && j < m:
 *     + a[i] < b[j]  -> đẩy a[i] vào hop, i++
 *     + a[i] > b[j]  -> đẩy b[j] vào hop, j++
 *     + a[i] == b[j] -> đẩy a[i] vào CẢ hop lẫn giao, tăng CẢ i++ và j++!
 * - Vét nốt phần còn dư của A (while i < n) và B (while j < m) vào hop!
 * Tự gõ lời giải bên dưới rồi bấm Cmd + S -> Cmd + Shift + B!
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int m, n; 
    cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    vector<int> hop; 
    vector<int> giao;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int i = 0; 
    int j = 0; 
    while (i < m && j < n){
       if(a[i] < b[j]) {
        hop.push_back(a[i]);
        i++;
       } else if (a[i] > b[j]){
        hop.push_back(b[j]);
        j++;
       } else if (a[i] == b[j]) {
        hop.push_back(a[i]);
        giao.push_back(a[i]);
        i++;
        j++;
       }
    }
    while (i < m)  {
        hop.push_back(a[i]);
        i++;
        
    }
    while(j < n)  {
        hop.push_back(b[j]);
        j++;
    }
    for(int x : hop) cout << x << " ";
    cout << "\n";
    for(int y : giao) cout << y << " ";
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
