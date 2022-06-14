#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int m = nums.size(), tar, left, right;
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            tar = -nums[i];
            left = i + 1, right = m - 1;
            if (left >= m || nums[left] > tar)
                break;
            while (left < right)
            {
                while (left < right && nums[left] + nums[right] > tar)
                    right--;
                if (left < right && nums[left] + nums[right] == tar)
                    ans.push_back({nums[i], nums[left], nums[right]});
                /* 跳过重复解 */
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                left++;
            };
        };
        /* 去除重复 */
        int n = ans.size();
        sort(ans.begin(), ans.end(), [](const auto &u, const auto &v) {
            if (u[0] == v[0])
            {
                if (u[1] == v[1])
                    return u[2] < v[2];
                else
                    return u[1] < v[1];
            }
            else
                return u[0] < v[0];
        });
        vector<vector<int>> res;
        if (n > 0)
            res.push_back(ans[0]);
        for (int i = 1; i < n; i++)
        {
            if (ans[i][0] != ans[i - 1][0] || ans[i][1] != ans[i - 1][1] || ans[i][2] != ans[i - 1][2])
                res.push_back(ans[i]);
        }
        return res;
    }
};

int main()
{
    vector<int> v = {0};
    Solution S;
    S.threeSum(v);
    return 0;
}