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
    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isOperator(s[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
        else
        {
            st.push(string(1, s[i]));
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