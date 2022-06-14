class Solution
{
  public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < group.size(); i++)
        {
            int g = group[i], p = profit[i];
            for (int j = n; j >= 0; j--)
            {
                if (j + g > n)
                    continue;
                for (int k = minProfit; k >= 0; k--)
                {
                    dp[j + g][min(k + p, minProfit)] = (dp[j + g][min(k + p, minProfit)] + dp[j][k]) % mod;
                };
            };
            // if (g <= n)
            //     dp[g][min(p, minProfit)]++;
        };

        for (int j = 0; j <= n; j++)
            ans = (ans + dp[j][minProfit]) % mod;
        return ans;
    }
};