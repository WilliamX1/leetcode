class Solution
{
  public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(),
             [](const vector<int> &v1, const vector<int> &v2) { return v1[0] < v2[0]; });

        int n = factory.size(), m = robot.size();
        vector<vector<long long>> dp(n, vector<long long>(m, 1e18));

        long long cost = 0;
        for (int k = 0; k < m && k + 1 <= factory[0][1]; k++)
        {
            cost += (long long)abs(factory[0][0] - robot[k]);
            dp[0][k] = cost;
        };

        long long ans = dp[0][m - 1];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cost = 0;

                dp[i][j] = dp[i - 1][j];

                for (int k = j; k >= 0 && j - k + 1 <= factory[i][1]; k--)
                {
                    cost += (long long)abs(factory[i][0] - robot[k]);

                    dp[i][j] = min(dp[i][j], (k > 0 ? dp[i - 1][k - 1] : 0) + cost);
                };

                ans = min(ans, dp[i][m - 1]);
            };
        return ans;
    }
};