class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = 0, len = nums.size(), ans = 0x80000000;
        for (int i = 0; i < len; i++) {
            if (tmp > 0) tmp += nums[i];
            else tmp = nums[i];

            ans = max(ans, tmp);
        };
        return ans;
    }
};