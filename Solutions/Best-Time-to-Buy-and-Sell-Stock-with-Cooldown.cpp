class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(3, 0));
        /*  dp[i][0] 表示当天不持股且没卖出
            dp[i][1] 表示当天持股且没卖出
            dp[i][2] 表示当天不持股且卖出 */
        dp[0][0] = 0, dp[0][1] = -prices[0], dp[0][2] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        };
        return max(dp[len - 1][0], dp[len - 1][2]);
    }
};