class Solution
{
  public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        double eps = 1e-7;
        double INFTY = 1e20;
        int n = dist.size();
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, INFTY));
        dp[0][0] = 0.;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j != i)
                {
                    dp[i][j] = min(dp[i][j], ceil(dp[i - 1][j] + (double)dist[i - 1] / speed - eps));
                };
                if (j != 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (double)dist[i - 1] / speed);
                };
            };
        };
        for (int j = 0; j <= n; j++)
        {
            if (dp[n][j] < hoursBefore + eps)
                return j;
        };
        return -1;
    }
};