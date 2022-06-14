#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        unordered_map<int, int> origin;
        int len = nums.size(), ans = 0;

        vector<unordered_map<int64_t, int>> dp(len);
        for (int i = 0; i < len; i++)
            for (int j = 0; j < i; j++)
            {
                int64_t d = int64_t(nums[i]) - int64_t(nums[j]);
                auto iter = dp[j].find(d);
                int cnt = iter == dp[j].end() ? 0 : iter->second;
                ans += cnt;
                dp[i][d] += cnt + 1;
            };
        return ans;
    }
};