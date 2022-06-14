class Solution
{
  public:
    int _maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size(), m = n / 3;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[1][0] = 0;
        dp[1][1] = slices[0];
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= min(i, m); j++)
            {
                dp[i][j] = max(dp[i - 2][j - 1] + slices[i - 1], dp[i - 1][j]);
            };
        return dp[n][m];
    };
    int maxSizeSlices(vector<int> &slices)
    {
        vector<int> v1 = slices, v2 = slices;
        int MIN = -1000000000;
        v1[0] = MIN;
        v2[v2.size() - 1] = MIN;
        return max(_maxSizeSlices(v1), _maxSizeSlices(v2));
    }
};