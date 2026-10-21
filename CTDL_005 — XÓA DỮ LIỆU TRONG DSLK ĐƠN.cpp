#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    Node *head = NULL; 
    Node *tail = NULL; 

    // 1. Nhập n phần tử và nối đuôi nhau thành danh sách
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        // Tạo ra một bạn mới
        Node *p = new Node();
        p->data = val;
        p->next = NULL;

        if (head == NULL)
        {
            // Nếu hàng chưa có ai, bạn này vừa là đầu vừa là đuôi
            head = tail = p;
        }
        else
        {
            // Nối bạn mới vào sau lưng bạn đuôi, rồi bạn mới biến thành đuôi
            tail->next = p;
            tail = p;
        }
    }

    int x;
    cin >> x; // Số cần xóa

    // 2. Xóa các số x nằm liên tiếp ở ĐẦU hàng
    while (head != NULL && head->data == x)
    {
        head = head->next;
    }

    // 3. Xóa các số x nằm ở GIỮA hoặc CUỐI hàng
    Node *p = head;
    while (p != NULL && p->next != NULL)
    {
        if (p->next->data == x)
        {
            // Bạn đằng sau mang số x -> bắc cầu qua đầu bạn đó
            p->next = p->next->next;
        }
        else
        {
            // Không phải số x -> bước chân lên kiểm tra tiếp
            p = p->next;
        }
    }

    // 4. In kết quả: Đi từ đầu hàng đến cuối hàng và in ra
    p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next; // Bước tiếp sang người sau
    }

    return 0;
}