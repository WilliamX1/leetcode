class Solution
{
  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int m = nums.size(), n = 0, tot = 0;
        for (const vector<int> &num : nums)
        {
            n = max(n, (int)num.size());
            tot += num.size();
        };
        vector<vector<vector<int>>> v(m + n - 1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                v[i + j].push_back({i, j});
            };
        };
        for (int i = 0; i < m + n - 1; i++)
            sort(v[i].begin(), v[i].end(), [](const vector<int> &a1, const vector<int> &b1) { return a1[0] > b1[0]; });
        vector<int> ans;
        for (int i = 0; i < m + n - 1; i++)
            for (int j = 0; j < v[i].size(); j++)
                ans.push_back(nums[v[i][j][0]][v[i][j][1]]);
        // vector<int> sumOf(m + n - 1, 0);
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < nums[i].size(); j++) {
        //         sumOf[i + j]++;
        //     };
        // };
        // for (int i = 1; i < m + n - 1; i++)
        //     sumOf[i] += sumOf[i - 1];

        // vector<int> ans(tot);
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < nums[i].size(); j++) {
        //         int k = 0;
        //         for (int s = i - 1; s >= 0; s--)
        //             if (i + j - s < nums[s].size())
        //                 k++;
        //         ans[sumOf[i + j] - k - 1] = nums[i][j];
        //     };
        // };

        // int upper = m + n;
        // for (int tot = 0; tot <= upper; tot++) {
        //     for (int i = min(tot, m - 1); i >= 0; i--) {
        //         int j = tot - i;
        //         if (i < nums.size() && j < nums[i].size()) {
        //             ans.push_back(nums[i][j]);
        //         };
        //     };
        // };

        return ans;
    }
};