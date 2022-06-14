class Solution
{
  public:
    int minInsertions(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0x7fffffff));

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                dp[i][j] = 0;

        for (int step = 1; step < n; step++)
            for (int i = 0; i + step < n; i++)
            {
                int j = i + step;

                if (s[i] == s[j])
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                dp[i][j] = min(dp[i][j], min(dp[i][j - 1] + 1, dp[i + 1][j] + 1));
            };

        return dp[0][n - 1];
    }
};