#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        /* 前缀和 + 哈希表 */
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        prefix[0] = 0;

        for (int i = 0; i < n; i++)
            prefix[i + 1] = (prefix[i] + nums[i]) % k;

        unordered_map<int, int> ans;
        for (int i = 0; i <= n; i++)
        {
            auto iter = ans.find(prefix[i]);
            if (iter != ans.end())
            {
                if (i - iter->second > 1)
                    return true;
            }
            else
            {
                ans.insert(make_pair(prefix[i], i));
            }
        }
        return false;
    }
};