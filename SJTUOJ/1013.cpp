#include <bits/stdc++.h>
#include <stdio.h>
#include <memory.h>
using namespace std;

long long C[100024];
long long W[100024];
long long dp[10010];

int main()
{
    int V, N; scanf("%d%d", &V, &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld%lld", &C[i], &W[i]);

    int index = N;
    long long cifang[20]; cifang[0] = 1;
    for (int i = 1; i < 18; i++) cifang[i] = cifang[i - 1] * 2;
    for (int i = 1; i <= N; i++)
        for (int j = 1; C[i] * cifang[j] <= V; j++)
        {
            ++index;
            C[index] = C[i] * cifang[j];
            W[index] = W[i] * cifang[j];
        }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= index; i++)
        for (int j = C[i]; j <= V; j++)
            dp[j] = max(dp[j], dp[j - C[i]] + W[i]);
    cout << dp[V];

    return 0;
}
