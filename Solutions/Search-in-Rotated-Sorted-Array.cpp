#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int x = lower_bound(nums.begin() + 1, nums.end(), nums[0], greater<int>()) - nums.begin();

        int find_left = lower_bound(nums.begin(), nums.begin() + x, target) - nums.begin();
        int find_right = lower_bound(nums.begin() + x, nums.end(), target) - nums.begin();
        if (find_left < n && nums[find_left] == target)
            return find_left;
        else if (find_right < n && nums[find_right] == target)
            return find_right;
        else
            return -1;
    }
};

int main()
{
    vector<int> nums = {3, 1};
    Solution S;
    cout << S.search(nums, 1);
    return 0;
}