#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
    string a, b;
    int result[210];
    cin >> a >> b;

    int len_A = a.length();
    int len_B = b.length();

    int A[210], B[210];
    for (int i = 0; i < len_A; i++)
        A[i] = a[len_A - i - 1] - '0';
    for (int i = 0; i < len_B; i++)
        B[i] = b[len_B - i - 1] - '0';

    int M = max(len_A, len_B);
    int m = min(len_A, len_B);

    for (int i = len_A; i < M; i++)
        A[i] = 0;
    for (int i = len_B; i < M; i++)
        B[i] = 0;

    int yushu = 0;

    for (int i = 0; i < M; i++)
    {
        if (i == 2) continue;

        result[i] = A[i] + B[i] + yushu;
        if (result[i] >= 10)
        {
            yushu = 1;
            result[i] -= 10;
        } else yushu = 0;
    }

    if (yushu == 1)
        cout << 1;
    for (int i = M - 1; i >= 0; i--)
    {
        if (i == 2) cout << '.';
        else cout << result[i];
    }
    return 0;
}
