#include <iostream>
#include <string>
#include <stack>

using namespace std;
void solve(string &s)
{
    stack<char> paren;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            paren.push(s[i]);
        }
        // xet ngoac dong ")"
        else
        {
            if (!paren.empty() && paren.top() == '(')
            {
                paren.pop();
            }
            else
            {
                paren.push(s[i]);
            }
        }
    }
    int m = 0;
    int n = 0;
    while (!paren.empty())
    {
        if (paren.top() == '(')
        {
            n++;
        }
        else
        {
            m++;
        }
        paren.top();
    }
    cout << m / 2 + n / 2 + m % 2 + n % 2;
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
// C2
// #include <iostream>
// #include <string>

// using namespace std;

// void solve()
// {
//     string s;
//     cin >> s;

//     // Dùng chính một chuỗi (string) để đóng vai trò làm Stack
//     // Bộ nhớ liên tục giúp các thao tác push/pop nhanh O(1) tuyệt đối
//     string st = "";

//     // BƯỚC 1: Quét và triệt tiêu (Logic y hệt của bạn)
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '(')
//         {
//             st.push_back(s[i]); // Tương đương paren.push()
//         }
//         else
//         {
//             // st.back() tương đương paren.top()
//             // st.empty() tương đương paren.empty()
//             if (!st.empty() && st.back() == '(')
//             {
//                 st.pop_back(); // Tương đương paren.pop()
//             }
//             else
//             {
//                 st.push_back(s[i]);
//             }
//         }
//     }

//     // BƯỚC 2: Đếm số lượng thừa trên Stack còn lại
//     // Vì dùng mảng, ta không cần phải pop từng cái ra để đếm nữa mà duyệt thẳng luôn, rất nhanh!
//     int m = 0; // Đếm số dấu ')'
//     int n = 0; // Đếm số dấu '('

//     for (int i = 0; i < st.length(); i++)
//     {
//         if (st[i] == '(') n++;
//         else m++;
//     }

//     // BƯỚC 3: Áp dụng công thức của bạn
//     cout << (m / 2) + (n / 2) + (m % 2) + (n % 2) << "\n";
// }

// int main()
// {
//     // Tối ưu I/O (Bắt buộc phải có để tránh kẹt luồng)
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     if (cin >> t)
//     {
//         while (t--)
//         {
//             solve();
//         }
//     }
//     return 0;
// }