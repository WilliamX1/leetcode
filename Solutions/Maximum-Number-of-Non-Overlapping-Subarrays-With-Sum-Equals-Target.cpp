class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int tot = 0;
        unordered_map<int, vector<int> > indexs;

        for (int i = 0; i < n; ++i) {
            if (i > 0) 
                dp[i] = dp[i - 1];
            tot += nums[i];
            if (tot == target)
                dp[i] = max(dp[i], 1);
            for (const int& idx : indexs[tot - target]) {
                dp[i] = max(dp[i], dp[idx] + 1);
            };
            indexs[tot].push_back(i);
        };
        return dp[n - 1];
    }
};