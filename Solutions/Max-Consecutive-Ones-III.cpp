class Solution
{
  public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = !nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + !nums[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] <= k)
                ans = max(ans, i + 1);
            else
                ans = max(ans, i - (int)(lower_bound(prefix.begin(), prefix.end(), prefix[i] - k) - prefix.begin()));
        };
        return ans;
    }
};