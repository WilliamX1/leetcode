class Solution
{
  public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0x7fffffff));
        for (int step = 0; step < m; step++)
            for (int start = 0; start + step < m; start++)
            {
                int end = start + step;
                if (step <= 1)
                    dp[start][end] = 0;
                for (int mid = start + 1; mid < end; mid++)
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid][end] + cuts[end] - cuts[start]);
            };
        return dp[0][m - 1];
    }
};