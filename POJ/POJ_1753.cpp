#include <iostream>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;

const int N = 4;
bool A[N + 2][N + 2];
bool B[N + 2][N + 2];
bool T[N + 2];

int main()
{
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    char ch; int i, j, k, tmp;

    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
        {
            cin >> ch;
            if (ch == 'b') A[i][j] = 1;  //黑色
            else if (ch == 'w') A[i][j] = 0;  //白色
        }

    int MIN = 100000;
    int M = pow(2.0, double(N));

    //全黑
    for (i = 0; i < M; i++)
    {
        tmp = i;
        for (j = 1; j <= N; j++)
        {
            B[1][j] = tmp % 2;
            tmp /= 2;
        }
        for (j = 1; j <= N; j++)
            T[j] = (A[1][j] + B[1][j - 1] + B[1][j] + B[1][j + 1]) % 2;

        for (j = 2; j <= N; j++)
        {
            for (k = 1; k <= N; k++)
                B[j][k] = !T[k];
            for (k = 1; k <= N; k++)
                T[k] = (A[j][k] + B[j - 1][k] + B[j][k] + B[j][k - 1] + B[j][k + 1]) % 2;
        }
        for (k = 1; k <= N && T[k] == 1; k++);
        if (k > N)
        {
            tmp = 0;
            for (j = 1; j <= N; j++)
                for (k = 1; k <= N; k++)
                    tmp += B[j][k];
            MIN = min(MIN, tmp);
        }
    }

    //全白
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            A[i][j] = !A[i][j];

    for (i = 0; i < M; i++)
    {
        tmp = i;
        for (j = 1; j <= N; j++)
        {
            B[1][j] = tmp % 2;
            tmp /= 2;
        }
        for (j = 1; j <= N; j++)
            T[j] = (A[1][j] + B[1][j - 1] + B[1][j] + B[1][j + 1]) % 2;

        for (j = 2; j <= N; j++)
        {
            for (k = 1; k <= N; k++)
                B[j][k] = !T[k];
            for (k = 1; k <= N; k++)
                T[k] = (A[j][k] + B[j - 1][k] + B[j][k] + B[j][k - 1] + B[j][k + 1]) % 2;
        }
        for (k = 1; k <= N && T[k] == 1; k++);
        if (k > N)
        {
            tmp = 0;
            for (j = 1; j <= N; j++)
                for (k = 1; k <= N; k++)
                    tmp += B[j][k];
            MIN = min(MIN, tmp);
        }
    }

    if (MIN != 100000) cout << MIN;
    else cout << "Impossible";

    return 0;
}
