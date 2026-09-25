#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void bubblesort(vector<int> &N)
{
    int n = N.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (N[j] > N[j + 1])
            {
                swap(N[j], N[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }

        cout << "Buoc " << (i + 1) << ":";
        for (int k = 0; k < n; k++)
        {
            cout << " " << N[k];
        }
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
        vector<int> N(n);
        for (int i = 0; i < n; i++)
        {
            cin >> N[i];
        }
        bubblesort(N);
    }
    return 0;
}
