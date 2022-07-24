class Solution
{
  public:
    long long countExcellentPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (const int &num : nums)
        {
            int tt = 0, tmp = num;
            while (tmp > 0)
            {
                tt += tmp & 1;
                tmp >>= 1;
            };
            umap[num] = tt;
        };

        vector<int> v;
        for (auto &iter : umap)
            v.push_back(iter.second);

        sort(v.begin(), v.end());
        long long ans = 0, size = v.size();
        for (int i = 0; i < size; i++)
        {
            long long index = lower_bound(v.begin(), v.end(), k - v[i]) - v.begin();
            ans += size - index;
        };
        return ans;
    }
};