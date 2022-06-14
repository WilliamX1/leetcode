class Solution
{
  public:
    bool OK(vector<int> nums, int mid, int m)
    {
        int tot = 0;
        for (int &num : nums)
        {
            if (num > mid)
                return false;
            else if (tot + num <= mid)
                tot += num;
            else
            {
                tot = num;
                m--;
            };
        };
        if (tot > 0)
            m--;
        return m >= 0;
    };
    int splitArray(vector<int> &nums, int m)
    {
        int left = 0, right = 1e9 + 7, mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (OK(nums, mid, m))
                right = mid - 1;
            else
                left = mid + 1;
        };
        return left;
    }
};