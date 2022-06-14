class Solution
{
  public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int step = 1; step < n; step++)
            for (int start = 0; start + step < n; start++)
            {
                int end = start + step;
                for (int i = start + 1; i < end; i++)
                {
                    dp[start][end] = max(dp[start][end], dp[start][i] + dp[i][end] + nums[start] * nums[i] * nums[end]);
                };
            };
        return dp[0][n - 1];
    };
};