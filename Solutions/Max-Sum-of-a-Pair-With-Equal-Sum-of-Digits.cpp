class Solution
{
  public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> umap;
        for (const int &num : nums)
        {
            int nn = num, tt = 0;
            while (nn)
            {
                tt += nn % 10;
                nn /= 10;
            };
            umap[tt].push_back(num);
        };
        int ans = -1;
        for (auto iter : umap)
        {
            vector<int> v = iter.second;
            sort(v.begin(), v.end(), greater<int>());
            if (v.size() >= 2)
                ans = max(ans, v[0] + v[1]);
        };
        return ans;
    }
};