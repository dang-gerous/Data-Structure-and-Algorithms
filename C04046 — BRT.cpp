/*
 * DAY 1 - PROBLEM 1: CLOSEST PAIRS (Code PTIT DSA06 Style - BRT)
 *
 * HOW TO TEST YOUR CODE RIGHT HERE IN ANTIGRAVITY IDE:
 *   1. Fix the 4 marked lines below inside solve()
 *   2. Save: Cmd + S
 *   3. Judge: Cmd + Shift + B  (runs Sample + Overflow + N=100,000 Stress
 * Tests!)
 *
 * Sample Input:
 * 2
 * 4
 * 6 -3 0 4
 * 5
 * 6 2 10 4 8
 *
 * Sample Output:
 * 2 1
 * 2 4
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

  // Your Round 1 draft is right below — fix the 4 spots and press Cmd + Shift +
  // B!
  sort(a.begin(), a.end()); // FIX 1: replace ';' with ','

  long long best = LLONG_MAX;
  int cnt = 0;

  for (int i = 0; i < n - 1; i++) { // FIX 2 & 3: stop at n - 1, and add { ... } around the loop body!
    long long d = abs(a[i + 1] - a[i]); // give 'd' type 'long long'
    if (d < best) {
      best = d; // FIX 4: reset cnt = 1 on new best; else if (d == best) cnt++;
      cnt = 1;
    } else if (d == best) {
      cnt++;
    }
}
cout << best << " " << cnt << "\n";
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
