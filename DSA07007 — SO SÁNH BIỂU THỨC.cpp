#include <iostream>
#include <string>
#include <stack>

using namespace std;

string simplify(const string &s)
{
    string res = "";
    stack<int> st;
    st.push(1);

    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == '+')
        {
            if (st.top() == 1)
                res += '+';
            else
                res += '-';
        }
        else if (s[i] == '-')
        {
            if (st.top() == 1)
                res += '-';
            else
                res += '+';
        }
        else if (s[i] == '(')
        {
            int sign = (i > 0 && s[i - 1] == '-') ? -1 : 1;
            st.push(st.top() * sign);
        }
        else if (s[i] == ')')
        {
            st.pop();
        }
        else
        {
            res += s[i];
        }
    }
    return res;
}

void solve()
{
    string p1, p2;
    cin >> p1 >> p2;

    if (simplify(p1) == simplify(p2))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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