class Solution
{
  public:
    int numOfWays(int n)
    {
        const int N = 12;
        int64_t ans = 0, mod = 1e9 + 7;
        vector<vector<int64_t>> dp(n, vector<int64_t>(N, 0));
        for (int j = 0; j < N; j++)
            dp[0][j] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5] + dp[i - 1][10]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][6] + dp[i - 1][8] + dp[i - 1][11]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][6] + dp[i - 1][7]) % mod;
            dp[i][3] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][7] + dp[i - 1][10]) % mod;
            dp[i][4] = (dp[i - 1][0] + dp[i - 1][6] + dp[i - 1][8] + dp[i - 1][9]) % mod;
            dp[i][5] = (dp[i - 1][0] + dp[i - 1][6] + dp[i - 1][7] + dp[i - 1][9] + dp[i - 1][10]) % mod;
            dp[i][6] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5] + dp[i - 1][11]) % mod;
            dp[i][7] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][11]) % mod;
            dp[i][8] = (dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][9] + dp[i - 1][10]) % mod;
            dp[i][9] = (dp[i - 1][4] + dp[i - 1][5] + dp[i - 1][8] + dp[i - 1][11]) % mod;
            dp[i][10] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][8] + dp[i - 1][11]) % mod;
            dp[i][11] = (dp[i - 1][1] + dp[i - 1][6] + dp[i - 1][7] + dp[i - 1][9] + dp[i - 1][10]) % mod;
        };
        for (int j = 0; j < N; j++)
            ans += dp[n - 1][j];
        ans %= mod;
        return ans;
    }
};