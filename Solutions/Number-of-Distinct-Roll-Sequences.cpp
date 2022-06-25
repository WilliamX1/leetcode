class Solution
{
  public:
    int distinctSequences(int n)
    {
        if (n == 1)
            return 6;

        int mod = 1e9 + 7;
        vector<vector<bool>> v = {{0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 0, 1, 0},
                                  {0, 1, 1, 0, 1, 1, 0}, {0, 1, 0, 1, 0, 1, 0}, {0, 1, 1, 1, 1, 0, 1},
                                  {0, 1, 0, 0, 0, 1, 0}};

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(7, vector<int>(7, 0)));

        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
                if (j != k && v[j][k])
                    dp[2][j][k] = 1;
        for (int i = 3; i <= n; i++)
            for (int j = 1; j <= 6; j++)
                for (int k = 1; k <= 6; k++)
                    if (j != k && v[j][k])
                        for (int s = 1; s <= 6; s++)
                            if (j != s && k != s && v[k][s])
                                dp[i][j][k] = (dp[i][j][k] + dp[i - 1][k][s]) % mod;
        int ans = 0;
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++)
                ans = (ans + dp[n][j][k]) % mod;

        return ans;
    }
};