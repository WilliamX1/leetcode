#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        /* 动态规划 */
        /* dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1] */
        const int mod = 1000000000 + 7;
        const int row_len = steps, col_len = min(steps, arrLen);
        long long int dp[row_len + 1][col_len + 2]; memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        for (int i = 1; i <= row_len; i++)
            for (int j = 1; j <= col_len; j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
        return dp[row_len][1];
    }
};