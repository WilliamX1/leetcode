class Solution
{
  public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9 + 7));
        for (int j = 0; j < n; j++)
            dp[0][j] = grid[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k != j)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                    };
                };
                dp[i][j] += grid[i][j];
            };
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};