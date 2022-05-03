class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<long long> dp(n + 1, 0);

        int index = 0, len = rides.size();
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            while (index < len && rides[index][1] == i) {
                long long start = rides[index][0], end = rides[index][1], tip = rides[index][2];
                dp[i] = max(dp[i], dp[start] + end - start + tip);
                index++;
            };
            // cout << dp[i] << ' ' ;
        };
        return dp[n];
    }
};