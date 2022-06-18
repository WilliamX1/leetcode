class Solution
{
  public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        int n = passingFees.size();
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, 1e9));
        dp[0][0] = passingFees[0];
        for (int time = 0; time <= maxTime; time++)
        {
            for (const vector<int> &edge : edges)
            {
                int c1 = edge[0], c2 = edge[1], t = edge[2];
                if (t <= time)
                {
                    dp[time][c1] = min(dp[time][c1], dp[time - t][c2] + passingFees[c1]);
                    dp[time][c2] = min(dp[time][c2], dp[time - t][c1] + passingFees[c2]);
                };
            };
        };
        int ans = 1e9;
        for (int i = 0; i <= maxTime; i++)
            ans = min(ans, dp[i][n - 1]);
        return ans == 1e9 ? -1 : ans;
    }
};