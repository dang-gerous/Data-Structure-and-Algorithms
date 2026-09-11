#include <iostream>
using namespace std;
int n, a[20];
bool isFinal = false;

void init()
{
  for (int i = 1; i <= n; i++)
  {
    a[i] = 0;
  }
}
// 2. Thuật toán sinh xâu nhị phân kế tiếp
void nextBinary()
{
  int i = n;
  while (i >= 1 && a[i] == 1)
  {
    a[i] = 0;
    i--;
  }
  if (i == 0)
  {
    isFinal = true; // Đã đến cấu hình cuối cùng (toàn số 1)
  }
  else
  {
    a[i] = 1;
  }
}
// 3. Hàm kiểm tra xâu đối xứng (thuận nghịch)
bool checkPalindrome()
{
  int l = 1, r = n;
  while (l < r)
  {
    if (a[l] != a[r])
      return false;
    l++;
    r--;
  }
  return true;
}
int main()
{
  cin >> n;
  init();

  while (!isFinal)
  {
    // Nếu là xâu thuận nghịch thì in ra
    if (checkPalindrome())
    {
      for (int i = 1; i <= n; i++)
      {
        cout << a[i] << " ";
      }
      cout << endl;
    }
    nextBinary(); // Sinh tiếp xâu tiếp theo
  }
  return 0;
}