class Solution
{
  public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        // | small | big | small | big | small | big | small |
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            ans[2 * i] = nums[i];
        };
        for (int i = (n + 1) / 2; i < n; i++)
        {
            ans[(i - (n + 1) / 2) * 2 + 1] = nums[i];
        };
        return ans;
    }
};