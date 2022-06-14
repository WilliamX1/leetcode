class Solution
{
  public:
    int numberOfArrays(string s, int k)
    {
        int n = s.size(), mod = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != '0')
            {
                string tmp;
                for (int j = i; j < n; j++)
                {
                    tmp.push_back(s[j]);
                    if (stol(tmp) <= k)
                    {
                        dp[i] += dp[j + 1];
                        dp[i] %= mod;
                    }
                    else
                        break;
                };
            };
        };
        return dp[0];
    }
};