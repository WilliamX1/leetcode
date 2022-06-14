class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<unordered_map<int64_t, bool>> m(n + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            m[i] = m[i + 1];
            m[i][nums[i]] = true;
        };

        set<vector<int>> s;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                {
                    if (m[k + 1][(int64_t)target - (int64_t)nums[i] - (int64_t)nums[j] - (int64_t)nums[k]])
                    {
                        vector<int> v = {nums[i], nums[j], nums[k],
                                         int((int64_t)target - (int64_t)nums[i] - (int64_t)nums[j] - (int64_t)nums[k])};
                        sort(v.begin(), v.end());
                        s.insert(v);
                    };
                };

        vector<vector<int>> ans;
        for (auto v : s)
        {
            ans.push_back(v);
        };
        return ans;
    }
};