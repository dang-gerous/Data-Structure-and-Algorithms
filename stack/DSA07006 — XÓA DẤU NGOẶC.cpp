#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <set>

using namespace std;

// === BIẾN TOÀN CỤC ===
string s;
vector<pair<int, int>> pairs;
int k;     // Chỉ khai báo, không gán ngay lúc này
int X[25]; // Khai báo mảng X dư dả một chút, không cần vector cho biến X
set<string> res;

// BƯỚC 3: XỬ LÝ KẾT QUẢ
void xu_ly_ket_qua()
{
    int tong_xoa = 0;
    for (int i = 0; i < k; i++)
        tong_xoa += X[i];
    if (tong_xoa == 0)
        return;

    vector<bool> bi_xoa(s.length(), false);
    for (int i = 0; i < k; i++)
    {
        if (X[i] == 1)
        {
            bi_xoa[pairs[i].first] = true;
            bi_xoa[pairs[i].second] = true;
        }
    }

    string chuoi_moi = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (!bi_xoa[i])
            chuoi_moi += s[i];
    }
    res.insert(chuoi_moi);
}

// BƯỚC 2: QUAY LUI
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;

        if (i == k - 1)
        {
            xu_ly_ket_qua();
        }
        else
        {
            Try(i + 1);
        }
    }
}

// BƯỚC 1: LẤY TỌA ĐỘ
void scanposparen()
{
    stack<int> st; // Chuyển stack vào trong để tự động làm mới mỗi test case
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            int open_pos = st.top();
            pairs.push_back({open_pos, i});
            st.pop();
        }
    }
}

int main()
{
    // Tối ưu tốc độ đọc ghi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Đọc liên tục cho đến khi hết file, không cần biến t
    while (cin >> s)
    {
        // 1. DỌN SẠCH DỮ LIỆU CŨ (Cực kỳ quan trọng nếu có nhiều test)
        pairs.clear();
        res.clear();

        // 2. Tìm tọa độ
        scanposparen();

        // 3. Chạy Quay lui
        k = pairs.size();
        if (k > 0)
        {
            Try(0);
        }

        // 4. In kết quả
        for (string ans : res)
        {
            cout << ans << "\n";
        }
    }
    return 0;
}