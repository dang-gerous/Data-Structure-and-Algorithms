#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

void solve()
{
    string s;
    cin >> s;
    stack<long long> st;

    for (int i = (int)s.length() - 1; i >= 0; i--)
    {
        if (isOperator(s[i]))
        {
            long long op1 = st.top();
            st.pop();
            long long op2 = st.top();
            st.pop();

            if (s[i] == '+')
                st.push(op1 + op2);
            else if (s[i] == '-')
                st.push(op1 - op2);
            else if (s[i] == '*')
                st.push(op1 * op2);
            else if (s[i] == '/')
                st.push(op1 / op2);
            else if (s[i] == '%')
                st.push(op1 % op2);
        }
        else
        {
            st.push(s[i] - '0');
        }
    }

    cout << st.top() << "\n";
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