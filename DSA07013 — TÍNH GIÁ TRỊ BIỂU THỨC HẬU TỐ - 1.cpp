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

    for (char c : s)
    {
        if (isOperator(c))
        {
            long long op2 = st.top();
            st.pop();
            long long op1 = st.top();
            st.pop();

            if (c == '+')
                st.push(op1 + op2);
            else if (c == '-')
                st.push(op1 - op2);
            else if (c == '*')
                st.push(op1 * op2);
            else if (c == '/')
                st.push(op1 / op2);
            else if (c == '%')
                st.push(op1 % op2);
        }
        else
        {
            st.push(c - '0');
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