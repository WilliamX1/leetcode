class Solution
{
  public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = s[0] != '0';
        dp[0][1] = s[1] != '1';
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = (s[i] != '0') + dp[i - 1][0];
            dp[i][1] = (s[i] != '1') + min(dp[i - 1][0], dp[i - 1][1]);
        };
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};