class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, len); dp[0] = 0;

        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j <= min(len - 1, i + nums[i]); j++)
                dp[j] = min(dp[j], dp[i] + 1);
        };
        return dp[len - 1];
    }
};