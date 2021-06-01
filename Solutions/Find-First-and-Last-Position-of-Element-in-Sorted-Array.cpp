#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (start == n || nums[start] != target) {
            return {-1, -1};
        } else {
            int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            return {start, end - 1};
        };
    }
};