class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        s.insert(s.begin(), ' ');
        p.insert(p.begin(), ' ');
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (p[i] == '*')
                {
                    for (int k = j; k >= 0; k--)
                        dp[i][j] |= dp[i - 1][k];
                }
                else if (p[i] == '?')
                    dp[i][j] |= i >= 1 && j >= 1 && dp[i - 1][j - 1];
                else if (i == 0 && j == 0)
                    dp[i][j] = true;
                else
                    dp[i][j] |= (p[i] == s[j]) && (i >= 1 && j >= 1 && dp[i - 1][j - 1]);
            };
        return dp[n - 1][m - 1];
    }
};