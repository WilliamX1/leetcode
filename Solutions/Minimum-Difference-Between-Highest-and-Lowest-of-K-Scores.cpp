#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0x7fffffff;
        int len = nums.size();
        for (int i = 0; i + k - 1 < len; i++)
            ans = min(nums[i + k - 1] - nums[i], ans);
        return ans;
    }
};