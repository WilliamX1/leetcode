class Solution
{
  public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> pre(n, 0), post(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] <= nums[i - 1])
                pre[i] = pre[i - 1] + 1;
            else
                pre[i] = 1;
        };
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < n - 1 && nums[i] <= nums[i + 1])
                post[i] = post[i + 1] + 1;
            else
                post[i] = 1;
        };
        vector<int> ans;
        for (int i = k; i < n - k; i++)
            if (pre[i - 1] >= k && post[i + 1] >= k)
                ans.push_back(i);
        return ans;
    }
};