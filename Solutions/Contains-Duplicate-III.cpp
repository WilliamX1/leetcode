#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        set<int64_t> _set;
        int _size = nums.size();
        for (int i = 0; i < _size; i++)
        {
            /* 条件 nums[i] - t <= nums[pos] <= nums[i] + t */
            auto pos = _set.lower_bound(int64_t(nums[i]) - int64_t(t));
            if (pos != _set.end() && *pos <= int64_t(nums[i]) + int64_t(t))
                return true;
            _set.insert(nums[i]);
            if (_set.size() > k)
                _set.erase(nums[i - k]); /*维护滑动窗口使得满足abs(i - pos) < k */
        };
        return false;
    }
};

int main()
{
    Solution S;
    vector<int> v = {1, 2, 3, 1};
    printf("%d", S.containsNearbyAlmostDuplicate(v, 3, 0));

    return 0;
}
