class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0, len = nums.size();
        while (idx < len && nums[idx] == 0) idx++;
        int cnt = idx;
        while (++idx < len) {
            if (nums[idx] - nums[idx - 1] == 0) return false;
            else if (nums[idx] - nums[idx - 1] == 1) continue;
            else if (cnt >= nums[idx] - nums[idx - 1] - 1) cnt -= nums[idx] - nums[idx - 1] - 1;
            else return false;
        };
        return true;
    }
};