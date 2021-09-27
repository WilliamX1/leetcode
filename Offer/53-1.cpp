class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
        return (upper_bound(nums.begin() + idx, nums.end(), target) - nums.begin()) - idx;
    }
};