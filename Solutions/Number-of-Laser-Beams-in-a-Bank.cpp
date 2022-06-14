class Solution
{
  public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<int> dp;
        for (int i = 0; i < bank.size(); i++)
        {
            int cnt = 0;
            for (int j = 0; j < bank[i].size(); j++)
            {
                cnt += bank[i][j] - '0';
            };
            if (cnt > 0)
                dp.push_back(cnt);
        };
        int tot = 0;
        for (int i = 1; i < dp.size(); i++)
            tot += dp[i] * dp[i - 1];
        return tot;
    }
};