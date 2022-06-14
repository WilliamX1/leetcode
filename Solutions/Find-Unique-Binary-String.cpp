#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        int min = 1 << n;
        vector<bool> flags(min, false);
        for (auto num : nums)
        {
            int ele = 0;
            for (int i = 0; i < n; i++)
                ele = (ele * 2) + (num[i] - '0');
            // cout << ele << endl;
            flags[ele] = true;
        };

        for (int i = 0; i < min; i++)
        {
            if (!flags[i])
            {
                string ans = "";
                int cnt = n;
                while (i > 0)
                {
                    ans = char((i & 1) + '0') + ans;
                    i >>= 1;
                    n--;
                };
                while (n > 0)
                {
                    ans = '0' + ans;
                    n--;
                };
                return ans;
            };
        };
        return "";
    }
};