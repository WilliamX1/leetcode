class Solution
{
  public:
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = max(i != 0 ? dp[i - 1][j] : 0, j != 0 ? dp[i][j - 1] : 0) + grid[i][j];
        return dp[m - 1][n - 1];
    }
};