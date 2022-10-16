class Solution
{
  public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int left = 0, right = 1e9 + 7, n = nums.size();

        vector<int64_t> numscopy;
        for (int i = 0; i < nums.size(); i++)
            numscopy.push_back(nums[i]);

        while (left <= right)
        {
            int64_t mid = (left + right) >> 1;

            vector<int64_t> v = numscopy;
            for (int i = n - 1; i > 0; i--)
                if (v[i] > mid)
                    v[i - 1] += v[i] - mid;
            if (v[0] <= mid)
                right = mid - 1;
            else
                left = mid + 1;
        };
        return left;
    }
};