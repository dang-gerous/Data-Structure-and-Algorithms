#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void pushBack(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int removeElements(Node *&head, int x)
{
    Node dummy(0);
    dummy.next = head;
    Node *prev = &dummy;
    Node *curr = head;
    int count = 0;

    while (curr != nullptr)
    {
        if (curr->data == x)
        {
            prev->next = curr->next;
            Node *temp = curr;
            curr = curr->next;
            delete temp;
            count++;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    head = dummy.next;
    return count;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pushBack(head, tail, val);
    }

    int x;
    cin >> x;

    removeElements(head, x);
    printList(head);

    return 0;
}