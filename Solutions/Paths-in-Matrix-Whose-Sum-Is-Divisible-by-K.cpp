class Solution
{
  public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        int ans = 0, mod = 1e9 + 7;
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int s = 0; s < k; s++)
                {
                    int tar = (s + grid[i][j]) % k;
                    if (i == 0 && j == 0)
                        continue;
                    else if (i == 0)
                        dp[i][j][tar] += dp[i][j - 1][s];
                    else if (j == 0)
                        dp[i][j][tar] += dp[i - 1][j][s];
                    else
                        dp[i][j][tar] += dp[i][j - 1][s] + dp[i - 1][j][s];
                    dp[i][j][tar] %= mod;
                };
        return dp[m - 1][n - 1][0];
    }
};