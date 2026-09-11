#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int a[30], b[30];
bool isFinal = false;

// 1. Khởi tạo cấu hình nhị phân đầu tiên (toàn số 0)
void init() {
    for (int i = 1; i <= n; i++) {
        b[i] = 0;
    }
}

// 2. Thuật toán sinh xâu nhị phân kế tiếp
void nextBinary() {
    int i = n;
    while (i >= 1 && b[i] == 1) {
        b[i] = 0;
        i--;
    }
    if (i == 0) {
        isFinal = true; // Đã sinh hết (tới cấu hình toàn 1)
    } else {
        b[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Sắp xếp tăng dần để các dãy con in ra theo thứ tự tăng dần
    sort(a + 1, a + n + 1);

    init();
    int count = 0;

    while (!isFinal) {
        // Tính tổng dãy con tương ứng với xâu nhị phân b
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] == 1) {
                sum += a[i];
            }
        }

        // Nếu tổng đúng bằng K
        if (sum == k) {
            count++;
            for (int i = 1; i <= n; i++) {
                if (b[i] == 1) {
                    cout << a[i] << " ";
                }
            }
            cout << "\n";
        }

        nextBinary(); // Sinh cấu hình nhị phân tiếp theo
    }

    // In ra tổng số dãy con tìm được ở dòng cuối
    cout << count << "\n";

    return 0;
}
