#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void applyOp(stack<long long> &values, char op)
{
    long long val2 = values.top();
    values.pop();
    long long val1 = values.top();
    values.pop();
    if (op == '+')
        values.push(val1 + val2);
    else if (op == '-')
        values.push(val1 - val2);
    else if (op == '*')
        values.push(val1 * val2);
    else if (op == '/')
        values.push(val1 / val2);
}

void solve()
{
    string s;
    cin >> s;

    stack<long long> values;
    stack<char> ops;

    for (int i = 0; i < (int)s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            long long val = 0;
            while (i < (int)s.length() && isdigit(s[i]))
            {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
        else if (s[i] == '(')
        {
            ops.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                applyOp(values, ops.top());
                ops.pop();
            }
            if (!ops.empty())
                ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i]))
            {
                applyOp(values, ops.top());
                ops.pop();
            }
            ops.push(s[i]);
        }
    }

    while (!ops.empty())
    {
        applyOp(values, ops.top());
        ops.pop();
    }

    cout << values.top() << "\n";
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