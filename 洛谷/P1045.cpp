#include <bits/stdc++.h>

using namespace std;

int* T;
int* base;
int* res;
const int N = 500 + 10;

void bigplus(int *T, int *base)
{
    int yushu = 0;
    for (int i = 1; i <= 500; i++)
    {
        T[i] += base[i] + yushu;
        if (T[i] >= 10)
        {
            T[i] -= 10;
            yushu = 1;
        }else yushu = 0;
    }
}
void bigminus1(int *A)
{
    int index = 1;
    A[index] -= 1;
    while(index <= 500 && A[index] < 0)
    {
        A[index] += 10;
        A[++index]--;
    }
}
int* bigmul(int* A, int* B)
{
    int yushu = 0;
    for (int i = 1; i < N; i++) res[i] = 0;

    for (int i = 1; i <= 500; i++)
    {
        yushu = 0;
        for (int j = 1; j <= 501 - i; j++)
        {
            res[i + j - 1] += A[i] * B[j] + yushu;
            if (res[i + j - 1] >= 10)
            {
                yushu = res[i + j - 1] / 10;
                res[i + j - 1] %= 10;
            }else yushu = 0;
        }
    }
    return res;
}

void fastPower2(int k)
{

    for (int i = 0; i < N; i++) base[i] = 0;

    base[1] = 2;
    T[1] = 1;

    while(k > 1)
    {
        if (k & 1)
            T = bigmul(T, base);
        base = bigmul(base, base);
        k = k >> 1;
    }

}
int main()
{
    int P; cin >> P;
    cout << int(P * log10(2) + 1) << endl;
    T = new int[N];
    base = new int[N];
    res = new int[N];
    for (int i = 0; i < N; i++) T[i] = 0;

    fastPower2(P);
    bigminus1(T);

    for (int i = 500; i >= 1; i--)
        printf("%d", T[i]);

    return 0;
}
