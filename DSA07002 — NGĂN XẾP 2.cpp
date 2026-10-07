#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string command;
    vector<int> stack;

    int q;
    cin >> q;
    while (q--)
    {
        cin >> command;
        if (command == "PUSH")
        {
            int value;
            cin >> value;
            stack.push_back(value);
        }
        else if (command == "PRINT")
        {
            if (!stack.empty())
            {
                cout << stack.back();
                cout << "\n";
            }
            else
            {
                cout << "NONE\n";
            }
        }
        else if (command == "POP")
        {
            if (!stack.empty())
            {
                stack.pop_back();
            }
        }
    }
    return 0;
}