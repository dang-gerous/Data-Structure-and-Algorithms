#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }

    vector<string> res; 

    while (true)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
        {
            s += to_string(a[i]);
        }
        res.push_back(s);

        int i = n - 1;
        while (i > 0 && a[i] > a[i + 1])
            i--;
        if (i == 0)
            break;
        int j = n;
        while (a[i] > a[j])
        {
            j--;
        }
        swap(a[i], a[j]);

        reverse(a.begin() + i + 1, a.end());
    }

    for (int i = (int)res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
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