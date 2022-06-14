class Solution
{
  public:
    int numOfArrays(int n, int m, int k)
    {
        vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(k + 1, vector<int64_t>(m + 1, 0)));

        int64_t ans = 0, mod = 1e9 + 7;

        for (int64_t s = 1; s <= m; s++)
            dp[0][1][s] = 1;

        for (int64_t i = 1; i < n; i++)
        {
            for (int64_t j = 1; j <= k; j++)
            {
                for (int64_t s = 1; s <= m; s++)
                {
                    for (int64_t ss = 1; ss < s; ss++)
                        dp[i][j][s] = (dp[i][j][s] + dp[i - 1][j - 1][ss]) % mod;
                    dp[i][j][s] = (dp[i][j][s] + dp[i - 1][j][s] * s % mod) % mod;
                    // cout << i << ' ' << j << ' ' << s << ' ' << dp[i][j][s] << endl;
                };
            };
        };
        for (int64_t s = 1; s <= m; s++)
        {
            ans = (ans + dp[n - 1][k][s]) % mod;
        }
        return ans;
    }
};