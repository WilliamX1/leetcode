class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1)
                    v.push_back(nums[j]);
            ans.insert(v);
        };
        vector<vector<int>> ret;
        for (const vector<int> &v : ans)
            ret.push_back(v);

        return ret;
    }
};