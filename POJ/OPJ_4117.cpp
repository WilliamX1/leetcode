#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int A[60][60];

int main()
{
    int N;
    memset(A, 0, sizeof(A));

    for (int i = 1; i <= 50; i++)
        for (int j = 1; j <= 50; j++)
            if (i == 1 || j == 1) A[i][j] = 1;
            else if (i == j) A[i][j] = A[i][j - 1] + 1;
            else if (i > j) A[i][j] = A[i][j - 1] + A[i - j][j];
            else A[i][j] = A[i][i];
    while(scanf("%d", &N) != EOF)
        printf("%d\n", A[N][N]);

    return 0;
}
