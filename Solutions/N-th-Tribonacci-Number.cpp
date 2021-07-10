class Solution {
public:
    int tribonacci(int n) {
        int m = max(n + 1, 4);
        vector<int> dp(m);
        dp[0] = 0, dp[1] = dp[2] = 1;
        for (int i = 3; i < m; i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};