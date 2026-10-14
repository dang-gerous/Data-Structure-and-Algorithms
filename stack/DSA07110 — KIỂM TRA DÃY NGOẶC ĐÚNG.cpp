#include <iostream>
#include <stack>
#include <string>

using namespace std;
void solve(string &s)
{
    stack<char> brackets;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            brackets.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (brackets.empty())
            {
                cout << "NO\n";
                return;
            }

            char top = brackets.top();
            brackets.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << (brackets.empty() ? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        solve(s);
    }
    return 0;
}