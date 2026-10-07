#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int m)
{
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];

    vector<int> hop;
    vector<int> giao;
    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            hop.push_back(A[i]);
            i++;
        }
        else if (A[i] > B[j])
        {
            hop.push_back(B[j]);
            j++;
        }
        else
        {
            hop.push_back(A[i]);
            giao.push_back(A[i]);
            i++;
            j++;
        }
    }

    while (i < n)
    {
        hop.push_back(A[i]);
        i++;
    }
    while (j < m)
    {
        hop.push_back(B[j]);
        j++;
    }

    for (int x : hop)
        cout << x << " ";
    cout << "\n";
    for (int x : giao)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        solve(n, m);
    }
    return 0;
}
