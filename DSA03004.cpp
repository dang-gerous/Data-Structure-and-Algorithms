#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sort digits in ascending order to minimize the leading digits
    sort(a.begin(), a.end());

    long long num1 = 0;
    long long num2 = 0;

    // Alternately distribute digits to form the two smallest possible numbers
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            num1 = num1 * 10 + a[i];
        }
        else
        {
            num2 = num2 * 10 + a[i];
        }
    }

    // Print the minimized sum
    cout << num1 + num2 << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}