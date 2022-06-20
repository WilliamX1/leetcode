class Solution
{
  public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size(), sum = 0;
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            sum += piles[i];
            for (int M = 1; M <= n; M++)
            {
                if (i + 2 * M >= n)
                {
                    dp[i][M] = sum;
                }
                else
                {
                    for (int x = 1; x <= 2 * M; x++)
                    {
                        dp[i][M] = max(dp[i][M], sum - dp[i + x][max(M, x)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};