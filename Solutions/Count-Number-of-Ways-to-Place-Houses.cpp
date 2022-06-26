class Solution
{
  public:
    int countHousePlacements(int n)
    {
        vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(2, vector<int64_t>(2, 0)));
        int64_t mod = 1e9 + 7;
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][1][0] + dp[i - 1][1][1]) % mod;
            dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0]) % mod;
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % mod;
            dp[i][1][1] = (dp[i - 1][0][0]) % mod;
        };
        return (int)((dp[n - 1][0][0] + dp[n - 1][0][1] + dp[n - 1][1][0] + dp[n - 1][1][1]) % mod);
    }
};