#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size(), count = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        mp.insert(make_pair(0, -1));

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                count++;
            else
                count--;

            auto iter = mp.find(count);
            if (iter != mp.end())
            {
                ans = max(ans, i - iter->second);
            }
            else
                mp.insert(make_pair(count, i));
        };

        return ans;
    }
};