class Solution
{
  public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1e9));
        dp[0][0] = 0;

        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m - i; j++)
            {
                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + multipliers[i + j - 1] * nums[i - 1]);
                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + multipliers[i + j - 1] * nums[n - j]);
            };

        int ans = -1e9;
        for (int i = 0; i <= m; i++)
            ans = max(ans, dp[i][m - i]);

        return ans;
    }
};