class Solution
{
  public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        events.push_back({0, 0, 0});
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
        int n = events.size(), idx = 0, ans = 0;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for (int i = 1; i < n; i++)
        {
            int x = events[i][0];
            int idx =
                upper_bound(events.begin(), events.end(), x, [&](int const x, vector<int> v) { return v[1] >= x; }) -
                events.begin() - 1;
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[idx][j - 1] + events[i][2]);

                ans = max(ans, dp[i][j]);
            };
        };

        return ans;
    }
};