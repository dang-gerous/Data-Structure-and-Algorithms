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

    while (cin >> command)
    {
        if (command == "push")
        {
            int value;
            cin >> value;
            stack.push_back(value);
        }
        else if (command == "show")
        {
            if (!stack.empty())
            {
                for (int i = 0; i < stack.size(); i++)
                {
                    cout << stack[i] << " ";
                }
                cout << "\n";
            }
            else
            {
                cout << "empty\n";
            }
        }
        else if (command == "pop")
        {
            if (!stack.empty())
            {
                stack.pop_back();
            }
        }
    }
    return 0;
}