class Solution
{
  public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, 0);
        int mod = 1e9 + 7;

        dp[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            if (i - zero >= 0)
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i - one >= 0)
                dp[i] = (dp[i] + dp[i - one]) % mod;
        };
        int ans = 0;
        for (int i = low; i <= high; i++)
            ans = (ans + dp[i]) % mod;
        return ans;
    }
};