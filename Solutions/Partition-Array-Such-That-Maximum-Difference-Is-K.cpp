class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int m = nums[0], ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - m > k) {
                m = nums[i];
                ans++;
            };
        };
        return ans;
    }
};