class Solution
{
  public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n, nums.front()), suffix(n, nums.back());
        for (int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = min(suffix[i + 1], nums[i]);

        for (int i = 0; i < n - 1; i++)
            if (prefix[i] <= suffix[i + 1])
                return i + 1;
        return -1;
    }
};