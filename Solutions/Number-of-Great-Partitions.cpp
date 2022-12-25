class Solution
{
  public:
    int countPartitions(vector<int> &nums, int k)
    {
        bool flag = false;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int64_t>> dp(n, vector<int64_t>(k + 1, 0));
        dp[0][min(nums[0], k)] = 1;

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        int64_t mod = 1e9 + 7, sum = (int64_t)nums[0];
        for (int i = 1; i < n; i++)
        {
            sum += nums[i];

            for (int j = 0; j <= k; j++)
                dp[i][j] = dp[i - 1][j];

            for (int j = 0; j <= k; j++)
            {
                dp[i][min(j + nums[i], k)] = (dp[i][min(j + nums[i], k)] + dp[i - 1][j]) % mod;

                if (j + nums[i] >= k && sum - (j + nums[i]) >= k)
                    flag = true;
            };
        };

        int64_t acc = 0;
        for (int i = 0; i < k; i++)
            acc = (acc + dp[n - 1][i]) % mod;
        // cout << acc << ' ' << dp[n - 1][k] << endl;
        return flag ? (dp[n - 1][k] + mod - acc) % mod : 0;
    };
};