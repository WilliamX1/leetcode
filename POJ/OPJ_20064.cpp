#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;

int A[110][110];

int main()
{
    memset(A, 0, sizeof(A));

    int N, M; scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; i++) scanf("%d", &A[i][1]);
    A[0][1] = -1e9;

    for (int j = 2; j <= N; j++)
        for (int i = j; i <= N; i++)
            for (int k = 1; k < i; k++)
                A[i][j] = max(A[i][j], A[i - k][j - 1] + A[k][1]);

    printf("%d", A[N][M]);

    return 0;
}
