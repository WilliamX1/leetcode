class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n * 6 + 1, 0));
        dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = i; j <= i * 6; j++) {
                for (int k = j - 1; k >= max(j - 6, 0); k--) {
                    dp[i][j] += dp[i - 1][k];
                };
            };
        vector<double> ans;
        int sum = accumulate(dp[n].begin() + n, dp[n].begin() + 6 * n + 1, 0);
        for (int i = n; i <= n * 6; i++) {
            ans.push_back(double(dp[n][i]) / double(sum));
        };
        return ans;
    }
};