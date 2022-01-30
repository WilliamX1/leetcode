#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int A[1010];
int dp[1010][40010];  //以i结尾余数为j的数量

const long long int Mod = 998244353;

int main()
{
    long long int n; scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    memset(dp, 0, sizeof(dp));

    long long int sum = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 40000; j++)
        {
            for (int k = i - 1; k >= 1; k--)
                if (0 <= j && j <= 20000 && A[i] - A[k] == j)
                    dp[i][j] += dp[k][j] + 1;
                else if (j > 20000 && A[i] - A[k] == 20000 - j)
                    dp[i][j] += dp[k][j] + 1;

            sum += (long long)dp[i][j];
            sum %= Mod;
        }
    cout << (sum + (long long)n) % Mod;

    return 0;
}
