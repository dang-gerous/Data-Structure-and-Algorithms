#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        a[i] = i;

    while (true)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << " ";

        int i = n - 1;
        while (i >= 1 && a[i] > a[i + 1])
        {
            i--;
        }

        if (i == 0)
            break;

        int j = n;
        while (a[i] > a[j])
        {
            j--;
        }
        swap(a[i], a[j]);

        reverse(a.begin() + i + 1, a.begin() + n + 1);
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
        solve();
    }
    return 0;
}