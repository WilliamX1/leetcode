class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int idx = 0;
        for (int& num : nums) {
            if (idx >= ans.size()) {
                ans.push_back(vector<int>());
                ans[idx].push_back(num);
            } else if (ans[idx].back() == num) {
                if (++idx >= ans.size())
                    ans.push_back(vector<int>());
                ans[idx].push_back(num);
            } else {
                idx = 0;
                ans[idx].push_back(num);
            };
        };
        return ans;
    }
};