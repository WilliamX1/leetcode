#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i - 1] >= nums[i])
                continue;
            else
            {
                int idx = i, x = nums[i];
                for (int j = i + 1; j < n; j++)
                {
                    if (x > nums[j] && nums[j] > nums[i - 1])
                    {
                        x = nums[j];
                        idx = j;
                    };
                };

                swap(nums[i - 1], nums[idx]);
                sort(nums.begin() + i, nums.end(), less<int>());
                return;
            };
        };
        sort(nums.begin(), nums.end(), less<int>());

        return;
    }
};

int main()
{
    vector<int> nums = {4, 2, 0, 2, 3, 2, 0};
    Solution S;
    S.nextPermutation(nums);
    return 0;
}