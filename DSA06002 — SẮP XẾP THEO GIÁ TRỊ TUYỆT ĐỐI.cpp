#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
void solve(int n, int x)
{
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    stable_sort(A.begin(), A.end(), [x](int a, int b)
                { return abs(x - a) < abs(x - b); });

    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x;
        cin >> x;
        solve(n, x);
    }

    return 0;
}