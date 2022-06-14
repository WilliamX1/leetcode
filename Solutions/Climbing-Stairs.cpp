class Solution
{
  public:
    int climbStairs(int n)
    {
        // vector<int> dp(n + 1, 1);
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // };
        // return dp[n];

        int x1 = 1, x2 = 1, tmp;
        while (n-- >= 2)
        {
            tmp = x2;
            x2 = x1 + x2;
            x1 = tmp;
        }
        return x2;
    }
};