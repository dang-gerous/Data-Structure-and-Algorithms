#include <iostream>
#include <unordered_set>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n))
        return 0;

    unordered_set<int> A;

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (A.find(val) == A.end())
        {
            A.insert(val);

            Node *p = new Node;
            p->data = val;
            p->next = NULL;

            if (head == NULL)
            {
                head = tail = p;
            }
            else
            {
                tail->next = p;
                tail = p;
            }
        }
    }

    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}