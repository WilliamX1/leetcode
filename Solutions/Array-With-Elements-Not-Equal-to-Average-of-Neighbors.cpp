class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<int> ans(len, 0);
        int idx = 0;
        for (int i = 0; i < len; i += 2) ans[i] = nums[idx++];
        for (int i = 1; i < len; i += 2) ans[i] = nums[idx++];
        return ans; 
    }
};