class Solution
{
  public:
    long long countBadPairs(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            nums[i] -= i;
        unordered_map<int, int> umap;
        for (const int &num : nums)
            umap[num]++;

        long long ans = 0, size = nums.size();
        for (auto iter : umap)
        {
            long long val = iter.second;
            ans += val * (val - 1) / 2;
        };
        ans = size * (size - 1) / 2 - ans;
        return ans;
    }
};