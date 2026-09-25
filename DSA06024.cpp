#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void selectionsort(vector<int> &A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(A[min], A[i]);
        }
        cout << "Buoc " << (i + 1) << ":";
        for (int k = 0; k < n; k++)
            cout << " " << A[k];
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n)
    {
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        selectionsort(A);
    }
    return 0;
}