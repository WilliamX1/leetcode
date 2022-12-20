#include <cmath>

class Solution
{
  public:
    int longestSquareStreak(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> idx;
        for (int i = 0; i < nums.size(); i++)
            idx[nums[i]] = i;

        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            int num = sqrt(nums[i]);
            if (num * num == nums[i] && idx.count(num))
            {
                dp[i] = dp[idx[num]] + 1;
            };
        };
        int ans = *max_element(dp.begin(), dp.end());
        return ans > 1 ? ans : -1;
    }
};