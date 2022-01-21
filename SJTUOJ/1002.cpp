#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int A[1010][1010];

int B[1010][1010];
int C[1010][1010];

int main()
{
    int L, W; scanf("%d%d", &L, &W);
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));

    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= W; j++)
            scanf("%d", &A[i][j]);
    int n1, n2; scanf("%d%d", &n1, &n2);
    int MAX = 0;

    for (int i = 1; i <= L; i++)
    {
        B[i][1] = 0;
        for (int j = 1; j <= n2; j++)
            B[i][1] += A[i][j];
    }

    for (int i = 1; i <= L; i++)
        for (int j = 2; j <= W; j++)
            B[i][j] = B[i][j - 1] - A[i][j - 1] + A[i][j + n2 - 1];

    for (int j = 1; j <= W; j++)
    {
        C[1][j] = 0;
        for (int i = 1; i <= n1; i++)
            C[1][j] += B[i][j];
    }

    for (int j = 1; j <= W; j++)
        for (int i = 2; i <= W; i++)
            C[i][j] = C[i - 1][j] - B[i - 1][j] + B[i + n1 - 1][j];

    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= W; j++)
            MAX = max(MAX, C[i][j]);

    cout << MAX;
    return 0;
}
