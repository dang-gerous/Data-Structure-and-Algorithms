#include <iostream>
#include <vector>

using namespace std;
void solve()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(k + 1);
    for (int i = 1; i < k + 1; i++)
    {
        cin >> a[i];
    }
    // thuat toan sinh tap ke tiep
    int i = k;
    while (i > 0 && a[i] == n - k + i)
        i -= 1;
    if (i <= 0)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        a[i] += 1;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << endl;
    // in ra ket qua
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