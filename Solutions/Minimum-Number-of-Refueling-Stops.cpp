class Solution
{
  public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        if (stations.empty())
            return startFuel >= target ? 0 : -1;

        stations.insert(stations.begin(), {0, 0});
        stations.insert(stations.end(), {target, 0});

        int n = stations.size();
        vector<vector<int64_t>> dp(n, vector<int64_t>(n, -1));
        dp[0][0] = startFuel;

        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++)
            {
                int64_t distance = stations[i][0] - stations[i - 1][0];
                if (dp[i - 1][j] >= distance)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] - distance);
                if (j > 0 && dp[i - 1][j - 1] > -1)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (int64_t)stations[i - 1][1] - distance);
            };
        for (int j = 0; j < n; j++)
            if (dp[n - 1][j] >= 0)
                return j;
        return -1;
    }
};