class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            if (index.count(nums[i]) && i - index[nums[i]] <= k) return true;
            else index[nums[i]] = i;
        };
        return false;
    }
};