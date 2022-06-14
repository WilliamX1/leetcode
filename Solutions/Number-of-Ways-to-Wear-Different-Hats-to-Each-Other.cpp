class Solution
{
  public:
    int numberWays(vector<vector<int>> &hats)
    {
        int n = hats.size(), mod = 1e9 + 7;
        int maxHatId = 0;
        for (int i = 0; i < n; i++)
        {
            for (const int &h : hats[i])
            {
                maxHatId = max(maxHatId, h);
            };
        };
        vector<vector<int>> hat2person(maxHatId + 1);
        for (int i = 0; i < n; i++)
        {
            for (const int &h : hats[i])
            {
                hat2person[h].push_back(i);
            };
        };

        vector<vector<int>> dp(maxHatId + 1, vector<int>((1 << n), 0));
        dp[0][0] = 1;
        for (int i = 1; i <= maxHatId; i++)
        {
            for (int mask = 0; mask < (1 << n); mask++)
            {
                dp[i][mask] = dp[i - 1][mask];
                for (int j : hat2person[i])
                {
                    if (mask & (1 << j))
                    {
                        dp[i][mask] += dp[i - 1][mask ^ (1 << j)];
                        dp[i][mask] %= mod;
                    };
                };
            };
        };
        return dp[maxHatId][(1 << n) - 1];
    }
};