class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int n, vector<int> combine, int idx) {
        if (idx == n) ans.emplace_back(combine);
        else {
            dfs(nums, n, combine, idx + 1);
            combine.push_back(nums[idx]);
            dfs(nums, n, combine, idx + 1);
            combine.pop_back();
        };
        return;
    };
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> combine;
        dfs(nums, nums.size(), combine, 0);
        return ans;
    }
};