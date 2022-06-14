class Solution
{
  public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int n = nums.size();
        set<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                cnt += !(nums[j] % p);

                if (cnt > k)
                    break;

                v.push_back(nums[j]);
                ans.insert(v);
            };
        };
        return ans.size();
        // int n = nums.size();
        // vector<int> flag(n);
        // for (int i = 0; i < n; i++)
        //     flag[i] = !(nums[i] % p);

        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1));
        // for (int i = 0; i < n; i++) {
        //     if (!flag[i]) dp[i][0].push_back(i);
        //     else dp[i][1].push_back(i);

        //     if (i == 0) continue;
        //     for (int j = 0; j <= k; j++) {
        //         if (flag[i]) {
        //             if (j > 0) {
        //                 for (const int& s : dp[i - 1][j - 1]) {
        //                     dp[i][j].push_back(s);
        //                 };
        //             };
        //         } else {
        //             for (const int& s : dp[i - 1][j]) {
        //                 dp[i][j].push_back(s);
        //             };
        //         };
        //     };
        // };

        // unordered_map<int, unordered_map<int, vector<int>>> cc;
        // for (int i = 0; i < n; i++) {
        //     vector<int> v;
        //     for (int j = i; j < n; j++) {
        //         v.push_back(nums[j]);
        //         cc[i][j] = v;
        //     };
        // };

        // set<vector<int>> ans;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j <= k; j++) {
        //         for (int& s : dp[i][j]) {
        //             ans.insert(cc[s][i]);
        //         };
        //     }
        // }

        // return ans.size();
    }
};