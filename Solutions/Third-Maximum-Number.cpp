#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int thirdMax(vector<int> &nums)
    {
        int64_t MMM = INT64_MIN, MM = INT64_MIN, M = INT64_MIN;
        for (auto num : nums)
        {
            if (num > MMM)
            {
                M = MM;
                MM = MMM;
                MMM = num;
            }
            else if (num == MMM)
                continue;
            else if (num > MM)
            {
                M = MM;
                MM = num;
            }
            else if (num == MM)
                continue;
            else if (num > M)
            {
                M = num;
            }
            else if (num == M)
                continue;
            else
                continue;
        };
        if (M != INT64_MIN)
            return M;
        else
            return MMM;
    }
};