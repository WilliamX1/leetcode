class Solution
{
  public:
    long long sellingWood(int m, int n, vector<vector<int>> &prices)
    {
        vector<vector<long long>> pricesHW(m + 1, vector<long long>(n + 1, 0));
        for (const vector<int> &p : prices)
            pricesHW[p[0]][p[1]] = p[2];

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = pricesHW[i][j];
                for (int k = i - 1; k > 0; k--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j]);
                };
                for (int k = j - 1; k > 0; k--)
                {
                    dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);
                };
            };
        };
        return dp[m][n];
    }
};