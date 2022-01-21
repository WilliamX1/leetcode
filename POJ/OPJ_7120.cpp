#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    int len_A = A.length();
    int len_B = B.length();

    int a[210], b[210];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    for (int i = 0; i < len_A; i++)
        a[i] = A[len_A - i - 1] - '0';
    for (int i = 0; i < len_B; i++)
        b[i] = B[len_B - i - 1] - '0';

    int res[510];
    memset(res, 0, sizeof(res));

    int yushu = 0;
    for (int i = 0; i <= len_A; i++)
    {
        for (int j = 0; j <= len_B; j++)
        {
            int tmp = a[i] * b[j];
            res[i + j] += yushu + tmp % 10;
            yushu = tmp / 10;
            if (res[i + j] >= 10)
                { yushu += res[i + j] / 10; res[i + j] %= 10;};
        }
    }

    int xb = 500;
    for (; xb >= 0 && res[xb] == 0; xb--);

    for (int i = xb; i >= 0; i--)
        printf("%d", res[i]);

    return 0;
}
