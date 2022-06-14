#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int len = nums.size();
        vector<int> idxs;
        idxs.push_back(-1);

        for (int i = 0; i < len; i++)
            if (nums[i])
                idxs.push_back(i);
        idxs.push_back(len);

        int n = idxs.size(), ans = 0;
        int left, right, L, R;
        if (goal == 0)
        {
            left = 0, right = 1;
            while (right < n)
            {
                ans += (idxs[right] - idxs[left]) * (idxs[right] - idxs[left] - 1) / 2;
                left++, right++;
            };
        }
        else
        {
            left = 1, right = goal;
            while (right < n - 1)
            {
                L = idxs[left] - idxs[left - 1];
                R = idxs[right + 1] - idxs[right];
                if (!!L ^ !!R == 0)
                    ans += L * R;
                else
                    ans += L + R;
                left++, right++;
            };
        };
        return ans;
    }
};