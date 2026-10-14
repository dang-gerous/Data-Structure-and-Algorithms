#include <iostream>
#include <string>
#include <stack>

using namespace std;

void solve(string &s)
{
    stack<bool> boolstack;
    // Giu nguyen khong doi dau
    boolstack.push(false);
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (i > 0 && s[i - 1] == '-')
            {
                boolstack.push(!boolstack.top());
            }
            else
            {
                boolstack.push(boolstack.top());
            }
        }
        else if (s[i] == ')')
        {
            boolstack.pop();
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            if (boolstack.top())
            {
                res += (s[i] == '+' ? '-' : '+');
            }
            else
            {
                res += s[i];
            }
        }
        else
        {
            res += s[i];
        }
    }

    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
    {
        cin.ignore();
        while (t--)
        {
            string s;
            getline(cin, s);
            solve(s);
        }
    }
    return 0;
}