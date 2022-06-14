#include <bits/stdc++.h>

using namespace std;

class Solution
{
  private:
    int _countRangeSum(vector<int> &nums, int64_t lower, int64_t upper, int64_t l, int64_t r)
    {
        if (r == l)
            return lower <= nums[l] && nums[l] <= upper;

        int m = (l + r) >> 1;
        int ans = _countRangeSum(nums, lower, upper, l, m) + _countRangeSum(nums, lower, upper, m + 1, r);

        vector<int64_t> l_presum, r_presum;
        for (int i = m; i >= l; i--)
            l_presum.push_back(nums[i]);
        for (int i = m + 1; i <= r; i++)
            r_presum.push_back(nums[i]);

        int l_size = l_presum.size(), r_size = r_presum.size();
        for (int i = 1; i < l_size; i++)
            l_presum[i] += l_presum[i - 1];
        for (int i = 1; i < r_size; i++)
            r_presum[i] += r_presum[i - 1];
        sort(l_presum.begin(), l_presum.end());
        sort(r_presum.begin(), r_presum.end());

        int ll = 0, rr = r_size - 1;
        while (ll < r_size && l_presum[0] + r_presum[ll] < lower)
            ll++;
        while (rr >= 0 && l_presum[0] + r_presum[rr] > upper)
            rr--;
        ll--;
        rr++;
        ans += rr - ll - 1;

        ll = max(ll, 0);
        rr = min(rr, r_size - 1);
        for (int i = 1; i < l_size; i++)
        {
            while (ll >= 0 && l_presum[i] + r_presum[ll] >= lower)
                ll--;
            while (rr < r_size && l_presum[i] + r_presum[rr] <= upper)
                rr++;
            ans += rr - ll - 1;
        };
        return ans;
    };

  public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        return _countRangeSum(nums, lower, upper, 0, nums.size() - 1);
    }
};

int main()
{
    Solution S;
    vector<int> arr = {-3, 1, 2, -2, 2, -1};
    cout << S.countRangeSum(arr, -3, 1);
    return 0;
}