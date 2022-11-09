class Solution
{
  public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<int>> values(n, vector<int>(n, 1));
        for (const vector<int> &m : mines)
            values[m[0]][m[1]] = 0;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, 0)));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                dp[i][j][0] = values[i][j] ? (i > 0 ? dp[i - 1][j][0] : 0) + 1 : 0;
                dp[i][j][2] = values[i][j] ? (j > 0 ? dp[i][j - 1][2] : 0) + 1 : 0;
            };
        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j][1] = values[i][j] ? (i < n - 1 ? dp[i + 1][j][1] : 0) + 1 : 0;
                dp[i][j][3] = values[i][j] ? (j < n - 1 ? dp[i][j + 1][3] : 0) + 1 : 0;
            }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int tmp = *min_element(dp[i][j].begin(), dp[i][j].end());
                ans = max(ans, tmp);
            };
        return ans;
    }
};