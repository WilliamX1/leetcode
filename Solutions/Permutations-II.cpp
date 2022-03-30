class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        perm(nums, 0, nums.size() - 1);
        return ans;
    };

    void perm(vector<int> nums, int left, int right) {
        if (left == right) {
            ans.push_back(nums);
        } else {
            for (int i = left; i <= right; i++) {
                if (i != left && nums[left] == nums[i]) continue;;
                swap(nums[left], nums[i]);
                perm(nums, left + 1, right);
            };
        };
    };
};