#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i % 2 == 0)
        {
            odd.push_back(A[i]);
        }
        else
        {
            even.push_back(A[i]);
        }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<int>());

    int index_odd = 0;
    int index_even = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << odd[index_odd++] << " ";
        }
        else
        {

            cout << even[index_even++] << " ";
        }
    }
    return 0;
}
