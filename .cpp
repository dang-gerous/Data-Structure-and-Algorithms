#include <iostream>
#include <stack>

using namespace std;
bool isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    getline(cin, str);
    stack<string> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (isoperator(str[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op2 + str[i] + op1 + ")";
            s.push(temp);
        }
        else
        {
            s.push(string(1, str[i]));
        }
        cout << s.top() << "\n";
    }
}