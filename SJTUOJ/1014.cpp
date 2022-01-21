#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int A[100010], B[100010], result[100010];
    string a, b; cin >> a >> b;
    int len_A = a.length();
    int len_B = b.length();

    int M = max(len_A, len_B);

    for (int i = 0; i < len_A; i++)
        A[i] = a[len_A - i - 1] - '0';
    for (int i = 0; i < len_B; i++)
        B[i] = b[len_B - i - 1] - '0';
    for (int i = len_A; i < M; i++)
        A[i] = 0;
    for (int i = len_B; i < M; i++)
        B[i] = 0;

    int yushu = 0;
    for (int i = 0; i < M; i++)
    {
        result[i] = A[i] + B[i] + yushu;
        if (result[i] >= 10)
        {
            result[i] -= 10;
            yushu = 1;
        }else yushu = 0;
    }

    if (yushu == 1) cout << 1;
    for (int i = M - 1; i >= 0; i--)
        cout << result[i];

    return 0;
}
