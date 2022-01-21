#include <iostream>
#include <stdio.h>
using namespace std;

// 数据大小要顾及，有时候累加会超过int
int main()
{
    int N, M; scanf("%d",&N);
    int i, j;
    int *A = new int[N];
    int *B = new int[N];
    long long int *dp = new long long int[N];

    for (i = 0; i < N; i++)
        scanf("%d",&A[i]);

    long long int MAX = -10000;

    /*M = N % 2 == 0 ? N / 2 : (N - 1) / 2;
    for (i = 1; i < M; i++)
    {
        B[i] = A[2 * i] + A[2 * i + 1];
        dp[i] = dp[i - 1] > 0 ? B[i] + dp[i - 1] : B[i];
        if (dp[i] > MAX) MAX = dp[i];
    }

    dp[0] = A[1] + A[2]; MAX = MAX > dp[0] ? MAX : dp[0];
    M = N % 2 == 0 ? N / 2 - 1 : (N - 1) / 2;
    for (i = 1; i < M; i++)
    {
        B[i] = A[2 * i + 1] + A[2 * i + 2];
        dp[i] = dp[i - 1] > 0? B[i] + dp[i - 1] : B[i];
        if (dp[i] > MAX) MAX = dp[i];
    }*/

    if (N % 2 == 0)
    {
        MAX = dp[0] = A[0] + A[1];
        for (i = 1; i < N / 2; i++)
        {
            B[i] = A[2 * i] + A[2 * i + 1];
            dp[i] = dp[i - 1] > 0 ? B[i] + dp[i - 1] : B[i];
            if (dp[i] > MAX) MAX = dp[i];
        }

        dp[0] = A[1] + A[2]; if (dp[0] > MAX) MAX = dp[0];
        for (i = 1; i < N / 2 - 1; i++)
        {
            B[i] = A[2 * i + 1] + A[2 * i + 2];
            dp[i] = dp[i - 1] > 0 ? B[i] + dp[i - 1] : B[i];
            if (dp[i] > MAX) MAX = dp[i];
        }
    }
    else
    {
        MAX = dp[0] = A[0] + A[1];
        for (i = 1; i < (N - 1) / 2; i++)
        {
            B[i] = A[2 * i] + A[2 * i + 1];
            dp[i] = dp[i - 1] > 0 ? B[i] + dp[i - 1] : B[i];
            if (dp[i] > MAX) MAX = dp[i];
        }

        dp[0] = A[1] + A[2]; if (dp[0] > MAX) MAX = dp[0];
        for (i = 1; i < (N - 1) / 2; i++)
        {
            B[i] = A[2 * i + 1] + A[2 * i + 2];
            dp[i] = dp[i - 1] > 0 ? B[i] + dp[i - 1] : B[i];
            if (dp[i] > MAX) MAX = dp[i];
        }
    }

    cout << MAX;

    return 0;
}
