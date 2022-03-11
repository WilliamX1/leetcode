class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), m = n * 100;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if (tot & 1) return false;

        vector<vector<bool>> dp(n, vector<bool>(m + 1, false));
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = dp[i - 1][j] || (j - nums[i] >= 0 && dp[i - 1][j - nums[i]]);

        return dp[n - 1][tot >> 1];
    }
};