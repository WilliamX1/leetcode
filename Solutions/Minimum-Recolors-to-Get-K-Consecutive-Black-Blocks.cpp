class Solution
{
  public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size(), ans = 1e9;
        vector<vector<int>> dp(n, vector<int>(k + 1, 1e9));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
            for (int j = 1; j <= min(i + 1, k); j++)
                dp[i][j] = min(dp[i][j], (i > 0 ? dp[i - 1][j - 1] : 0) + (blocks[i] == 'W'));
            ans = min(ans, dp[i][k]);
        };
        return ans;
    }
};