class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int64_t left = 0, right = 0, n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) right += (int64_t) nums[i];
        for (int64_t i = 0; i < n - 1; ++i)
            ans += (left += (int64_t) nums[i]) >= (right -= (int64_t) nums[i]);
        return ans;
    }
};