class Solution {
public:
    int getMaximumGenerated(int n) {
        if (!n) return 0;
        vector<int> nums(n + 1, 0);
        nums[0] = 0, nums[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i & 1) nums[i] = nums[i >> 1] + nums[1 + (i >> 1)];
            else nums[i] = nums[i >> 1];
        };
        return *max_element(nums.begin(), nums.end());
    }
};