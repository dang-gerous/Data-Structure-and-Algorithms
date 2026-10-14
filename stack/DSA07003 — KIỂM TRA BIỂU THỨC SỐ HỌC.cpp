#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool hasduplicateparentheses(string &expr)
{
    stack<char> st;
    for (char x : expr)
    {
        if (x == ')')
        {
            char top = st.top();
            st.pop();
            bool hasoperator = false;
            while (top != '(' && !st.empty())
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    hasoperator = true;
                }
                top = st.top();
                st.pop();
            }
            if (!hasoperator)
            {
                return true;
            }
        }
        else
        {
            st.push(x);
        }
    }
    return false;
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
        string expr;
        getline(cin, expr);
        if(hasduplicateparentheses(expr)) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    return 0;
}