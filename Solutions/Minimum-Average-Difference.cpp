class Solution
{
  public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int64_t> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + (int64_t)nums[i];
        };
        int ans_idx = 0, ans_tot = abs((prefix[n - 1] - prefix[0]) / (n - 1) - prefix[0]);
        for (int i = 1; i < n; i++)
        {
            int tot = abs((i == n - 1 ? 0 : abs((prefix[n - 1] - prefix[i]) / (n - i - 1))) - prefix[i] / (i + 1));
            if (tot < ans_tot)
            {
                ans_tot = tot;
                ans_idx = i;
            };
        };
        return ans_idx;
    }
};