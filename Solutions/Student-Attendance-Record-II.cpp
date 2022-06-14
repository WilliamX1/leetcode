#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int checkRecord(int n)
    {
        /* dp[i][j][k] 表示到第i天已经缺勤j次且连续迟到k次的记录情况数量 */
        vector<vector<vector<int64_t>>> dp(n + 1, vector<vector<int64_t>>(2, vector<int64_t>(3, 0)));
        dp[0][0][0] = 1;
        int64_t mod = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod;
            dp[i][0][1] = dp[i - 1][0][0] % mod;
            dp[i][0][2] = dp[i - 1][0][1] % mod;
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] +
                           dp[i - 1][1][2]) %
                          mod;
            dp[i][1][1] = dp[i - 1][1][0] % mod;
            dp[i][1][2] = dp[i - 1][1][1] % mod;

            // cout << dp[i][0][0] << ' ' << dp[i][0][1] << ' ' << dp[i][0][2] << ' '
            //     << dp[i][1][0] << ' ' << dp[i][1][1] << ' ' << dp[i][1][2] << endl;
        };
        return (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % mod;
    }
};