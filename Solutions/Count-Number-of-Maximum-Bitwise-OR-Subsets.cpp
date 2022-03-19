class Solution {
public:
    int _countMaxOrSubsets(vector<int>& nums, const int& N, const int& idx, const int cur, const int& target) {
        if (idx == N) return 0;
        return _countMaxOrSubsets(nums, N, idx + 1, cur, target) + ((cur | nums[idx]) == target) + _countMaxOrSubsets(nums, N, idx + 1, cur | nums[idx], target);;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (const int& num : nums)
            target |= num;
        return _countMaxOrSubsets(nums, nums.size(), 0, 0, target);
    }
};