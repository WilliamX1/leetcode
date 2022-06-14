class Solution
{
  public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int len = cost.size();
        vector<int> dp(len + 2, 0x7fffffff);
        dp[0] = dp[1] = 0;
        for (int i = 0; i < len; i++)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + cost[i]);
            dp[i + 2] = min(dp[i + 2], dp[i] + cost[i]);
        }
        return dp[len];
    };
};