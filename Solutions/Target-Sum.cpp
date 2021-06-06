#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int res = 0;
    void simulate(vector<int>& nums, int target, int idx, int ans) {
        if (idx == nums.size()) {
            if (ans == target)  res++;
            return;
        }

        simulate(nums, target, idx + 1, ans + nums[idx]);
        simulate(nums, target, idx + 1, ans - nums[idx]);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /* 模拟 */
        simulate(nums, target, 0, 0);
        return res;
    }
};