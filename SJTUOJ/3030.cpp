#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
long long w[128];
long long v[128];
long long dp[1024];

int main()
{
    int T, M; scanf("%d%d", &T, &M);
    for (int i = 1; i <= M; i++)
        scanf("%lld%lld", &w[i], &v[i]);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= M; i++)
        for (int j = T; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    printf("%lld\n", dp[T]);

    return 0;
}
