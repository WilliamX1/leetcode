#include <bit>
#include <bitset>
#include <cstdint>
#include <iostream>

class Solution
{
  public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> answer;
        for (uint32_t i = 0; i < (1 << n); i++)
        {
            if (__builtin_popcount(i) == k)
            {
                vector<int> ans;
                for (int j = 0; j < n; j++)
                    if ((i >> j) & 1)
                        ans.push_back(j + 1);
                answer.push_back(ans);
            };
        };
        return answer;
    }
};