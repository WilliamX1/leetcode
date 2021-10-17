class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), idx = 0, sum = 1, ans = 0;
        if (k <= 1) return 0;
        for (int i = 0; i < n; i++)
        {
            while (idx < n && sum < k) sum *= nums[idx++];
            ans += idx - i - (sum >= k);
            if (idx < n) sum /= nums[--idx];
            sum /= nums[i];
        };
        return ans;
    }
};