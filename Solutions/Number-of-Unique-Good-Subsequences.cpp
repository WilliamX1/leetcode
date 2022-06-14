class Solution
{
  public:
    int numberOfUniqueGoodSubsequences(string s)
    {
        int n = s.size();
        int dp0 = 0, dp1 = 0, mod = 1e9 + 7, has0 = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                has0 = 1;
                dp0 = (dp0 + dp1 + 1) % mod;
            }
            else
            {
                dp1 = (dp0 + dp1 + 1) % mod;
            }
        }
        return (dp1 + has0) % mod;
    }
};