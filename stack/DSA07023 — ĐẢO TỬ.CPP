#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

void solve(string &s)
{
    stack<string> con;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        con.push(word);
    }
    bool flag = true;
    while (!con.empty())
    {
        if (!flag)
        {
            cout << " ";
        }
        cout << con.top();
        con.pop();
        flag = false;
    }
    cout << "\n";
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