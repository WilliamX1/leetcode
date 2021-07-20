class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));

        dp[0][1] = nums[0];

        int ans = nums[0];
        for (int i = 1; i < len; i++)
        {
            for (int j = i - 1; j >= max(0, i - 3); j--)
                dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]));
            
            dp[i][1] = nums[i] + dp[i - 1][0];
            for (int j = i - 2; j >= max(0, i - 4); j--)
                dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]) + nums[i]);
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};