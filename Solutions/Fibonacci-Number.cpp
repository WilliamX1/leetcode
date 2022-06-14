class Solution
{
  public:
    int fib(int n)
    {
        int m = max(2, n + 1);
        vector<int> dp(m);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < m; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        };
        return dp[n];
    }
};