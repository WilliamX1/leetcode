class Solution
{
  public:
    int minimumDeletions(vector<int> &nums)
    {
        int min_val = nums[0], min_idx = 0, max_val = nums[0], max_idx = 0, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < min_val)
            {
                min_val = nums[i];
                min_idx = i;
            };
            if (nums[i] > max_val)
            {
                max_val = nums[i];
                max_idx = i;
            };
        };
        int ans = 0x7fffffff;
        int m = min(min_idx, max_idx), M = max(min_idx, max_idx);
        ans = min(ans, m + 1 + n - M);
        ans = min(ans, n - m);
        ans = min(ans, M + 1);
        return ans;
    }
};