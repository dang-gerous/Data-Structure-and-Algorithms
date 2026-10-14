#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n)
{
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        if (left == right)
        {
            cout << A[left] << " ";
            break;
        }
        cout << A[right] << " " << A[left] << " ";
        left++;
        right--;
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
        solve(n);
    }
    return 0;
}