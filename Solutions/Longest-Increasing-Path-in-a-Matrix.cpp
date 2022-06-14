class Solution
{
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        bool flag;
        int ans = 0;
        do
        {
            flag = false;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                {
                    if (i > 0 && matrix[i - 1][j] > matrix[i][j] && dp[i - 1][j] + 1 > dp[i][j])
                        flag = dp[i][j] = dp[i - 1][j] + 1;
                    if (i < m - 1 && matrix[i + 1][j] > matrix[i][j] && dp[i + 1][j] + 1 > dp[i][j])
                        flag = dp[i][j] = dp[i + 1][j] + 1;
                    if (j > 0 && matrix[i][j - 1] > matrix[i][j] && dp[i][j - 1] + 1 > dp[i][j])
                        flag = dp[i][j] = dp[i][j - 1] + 1;
                    if (j < n - 1 && matrix[i][j + 1] > matrix[i][j] && dp[i][j + 1] + 1 > dp[i][j])
                        flag = dp[i][j] = dp[i][j + 1] + 1;

                    ans = max(ans, dp[i][j]);
                };
        } while (flag);
        return ans;
    }
};