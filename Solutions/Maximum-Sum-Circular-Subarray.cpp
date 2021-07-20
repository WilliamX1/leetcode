#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MIN = -100000000;
    int find(vector<int>& nums) {
        int len = nums.size();
        int prev = 0, cur = 0, ans = MIN;
        for (int i = 0; i < len; i++)
        {
            cur = prev > 0 ? prev + nums[i] : nums[i];
            prev = cur;
            ans = max(ans, cur);
        }
        return ans;
    };
    int findPreAndPost(vector<int>& nums) {
        int len = nums.size();
        vector<int> normal_prefix(len, 0), reverse_prefix(len, 0);
        vector<int> normal_max(len, 0), reverse_max(len, 0);
        
        normal_prefix[0] = normal_max[0] = nums[0];
        for (int i = 1; i < len; i++)
        {
            normal_prefix[i] = normal_prefix[i - 1] + nums[i];
            normal_max[i] = max(normal_max[i - 1], normal_prefix[i]);
        };

        reverse_prefix[len - 1] = reverse_max[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            reverse_prefix[i] = reverse_prefix[i + 1] + nums[i];
            reverse_max[i] = max(reverse_max[i + 1], reverse_prefix[i]);
        };

        int ans = MIN;
        for (int i = 0; i < len - 1; i++)
            ans = max(ans, normal_max[i] + reverse_max[i + 1]);
        return ans;
    };
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = find(nums);
        ans = max(ans, findPreAndPost(nums));
        return ans;
    }
};