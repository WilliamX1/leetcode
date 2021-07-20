class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0], len = nums.size();
        for (int i = 1; i < len; ++i) {
            int mx = maxF, mn = minF, num = nums[i];
            maxF = max(mx * num, max(num, mn * num));
            minF = min(mn * num, min(num, mx * num));
            ans = max(maxF, ans);
        };
        return ans;
    }
};