#include <iostream>
#include <string>
using namespace std;

int A[1000010];
int B[1000010];
int C[1000100];
int main()
{
    string a, b; cin >> a >> b;

    int len_A = a.length();
    int len_B = b.length();

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
        C[i] = yushu + A[i] + B[i];
        if (C[i] >= 10)
        {
            C[i] -= 10;
            yushu = 1;
        }else yushu = 0;
    }

    if (yushu == 1) cout << 1;
    for (int i = M - 1; i >= 0; i--)
        cout << C[i];

    return 0;
}
