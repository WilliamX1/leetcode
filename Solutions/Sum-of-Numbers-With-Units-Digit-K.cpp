class Solution
{
  public:
    int minimumNumbers(int num, int k)
    {
        vector<int> dp(num + 1, 1e5);
        dp[0] = 0;

        for (int i = 1; i <= num; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if ((i - j) % 10 == k)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[num] == 1e5 ? -1 : dp[num];
    }
};