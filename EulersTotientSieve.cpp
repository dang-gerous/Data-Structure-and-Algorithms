#include <iostream>
#include <vector>

using namespace std;

void solve(int n)
{
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
    {
        phi[i] = i;
    }

    // Sàng Phi Euler để tính số lượng số nguyên tố cùng nhau với i
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }

    long long count = 1;

    for (int b = 1; b <= n; b++)
    {
        count += phi[b];
    }

    cout << count << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n)
    {
        solve(n);
    }
    return 0;
}