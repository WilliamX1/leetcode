class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int len = nums.size(), tot = 0, ans = 0;
        for (int i = 0; i < len; i++) {
            if (i == 0 || nums[i] > nums[i - 1]) tot += nums[i];
            else tot = nums[i];
            ans = max(ans, tot);
        };
        return ans;
    }
};