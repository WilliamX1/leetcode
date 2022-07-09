class Solution
{
  public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int64_t k = k1 + k2;
        vector<int64_t> v;
        for (int64_t i = 0; i < nums1.size(); i++)
            v.push_back(abs(nums1[i] - nums2[i]));

        int64_t left = 0, right = 1e5 + 7;
        while (left <= right)
        {
            int64_t mid = (left + right) >> 1;

            int64_t tt = 0;
            for (const int &num : v)
                tt += max(0L, (int64_t)(num - mid));

            if (tt <= k)
                right = mid - 1;
            else
                left = mid + 1;
        };

        int64_t tt = 0;
        for (int64_t &num : v)
        {
            tt += max(0L, num - left);
            num = min(num, left);
        };

        tt = k - tt;
        for (int64_t &num : v)
        {
            if (tt == 0)
                break;
            else if (num && num == left)
            {
                num--;
                tt--;
            }
            else
                continue;
        };
        int64_t ans = 0;
        for (const int &num : v)
            ans += (int64_t)num * (int64_t)num;

        return ans;
    }
};