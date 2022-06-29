class Solution
{
  public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int64_t> ans(n);
        for (int i = 0; i < min(n, k); i++)
            ans[i] = ans[n - i - 1] = -1;
        int64_t tot = 0, idx = k, more = n - 2 * k - 1;

        for (int i = 0; i < min(n, 2 * k + 1); i++)
            tot += (int64_t)nums[i];
        if (more-- >= 0)
            ans[idx] = tot;

        while (more-- >= 0)
        {
            tot -= nums[idx - k];
            tot += nums[++idx + k];
            ans[idx] = tot;
        };
        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            if (ans[i] >= 0)
                ret[i] = ans[i] / (int64_t)(2 * k + 1);
            else
                ret[i] = ans[i];
        };

        return ret;
    }
};