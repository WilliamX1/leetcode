#include <iostream>
#include <cmath>
using namespace std;

const int inf = 1e9;

int A[12];
int B[12][12];

int main()
{
    int N, K; scanf("%d%d", &N, &K);

    for (int i = 1; i <= N; i++) A[i] = inf;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &B[i][j]);

    for (int i = 1; i <= N; i++) //初始化到城市1的距离
        A[i] = B[1][i];

    for (int i = 2; i <= N; i++)
    {
        for (int j = i - 1; j > 1; j--)
            A[i] = min(A[i], B[i][j] + A[j]);
    }

    for (int i = N; i >= 1; i--)
        if (A[i] <= K)
        {
            printf("%d", i);
            break;
        }

    return 0;
}
