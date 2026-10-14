#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string u;
    int n = u.length();
    getline(cin, u);
    int left = 1;
    stack<int> right;
    for (int i = 0; i < n; i++)
    {
        if (u[i] == '(')
        {
            cout << left << " ";
            right.push(left);
            left++;
        }
        else if (u[i] == ')')
        {

            cout << right.top() << " ";
            right.pop();
        }
    }
    return 0;
}