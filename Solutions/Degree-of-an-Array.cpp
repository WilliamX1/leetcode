class Solution
{
  public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        unordered_map<int, int> left, right;
        int degree = 0;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            if (left.find(nums[i]) == left.end())
                left[nums[i]] = i;
            right[nums[i]] = i;

            umap[nums[i]]++;
            if (umap[nums[i]] > degree)
            {
                degree = umap[nums[i]];
                v.clear();
                v.push_back(nums[i]);
            }
            else if (umap[nums[i]] == degree)
            {
                v.push_back(nums[i]);
            }
            else
            {
            };
        };
        int ans = 1e9;
        for (int i = 0; i < v.size(); i++)
        {
            ans = min(ans, right[v[i]] - left[v[i]] + 1);
        };
        return ans;
    };
};