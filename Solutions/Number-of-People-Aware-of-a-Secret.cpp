class Solution
{
  public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int mod = 1e9 + 7, ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + delay; j < min(n, i + forget); j++)
                dp[j] = (dp[j] + dp[i]) % mod;
            if (n - i <= forget)
                ans = (ans + dp[i]) % mod;
        };
        return ans;
    }
};