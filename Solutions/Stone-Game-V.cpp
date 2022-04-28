class Solution {
public:
    int _stoneGameV(const vector<int>& stoneValue, vector<vector<int>>& dp, const vector<int>& prefix, const int& left, const int& right) {
        if (left == right || dp[left][right]) 
            return dp[left][right];

        int sum = prefix[right] - prefix[left] + stoneValue[left];
        int cnt = 0;
        for (int i = left; i < right; i++) {
            cnt += stoneValue[i];
            if (cnt <= sum - cnt)
                dp[left][right] = max(dp[left][right], cnt + _stoneGameV(stoneValue, dp, prefix, left, i));
            if (sum - cnt <= cnt)
                dp[left][right] = max(dp[left][right], sum - cnt + _stoneGameV(stoneValue, dp, prefix, i + 1, right));
        };
        return dp[left][right];
    };
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> prefix(n, 0);
        prefix[0] = stoneValue[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + stoneValue[i];
        return _stoneGameV(stoneValue, dp, prefix, 0, n - 1);
    }
};