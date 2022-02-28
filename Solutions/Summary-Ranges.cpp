class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;

        int idx = 0, tot = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((long long) nums[i + 1] - (long long) nums[i] != 1) {
                if (tot == 1)
                    ans.push_back(to_string(nums[idx]));
                else
                    ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[i]));
                idx = i + 1;
                tot = 1;
            } else tot++;
        };
        if (tot == 1)
            ans.push_back(to_string(nums[idx]));
        else
            ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[nums.size() - 1]));
        return ans;
    }
};