class Solution
{
  public:
    int maxTrailingZeros(vector<vector<int>> &grid)
    {
        const int N = 1e3;
        vector<vector<int>> umap(N + 1, vector<int>(3, 0)); // 预处理 10 的倍数 5 的倍数和 2 的倍数
        for (int i = 1; i <= N; ++i)
        {
            int tmp = i;
            while (tmp > 0)
            {
                if (tmp % 10 == 0)
                {
                    umap[i][0]++;
                    tmp /= 10;
                }
                else
                    break;
            };
            while (tmp > 0)
            {
                if (tmp % 5 == 0)
                {
                    umap[i][1]++;
                    tmp /= 5;
                }
                else
                    break;
            };
            while (tmp > 0)
            {
                if (tmp % 2 == 0)
                {
                    umap[i][2]++;
                    tmp /= 2;
                }
                else
                    break;
            };
        };

        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(
            m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(3, 0)))); // 0 上 1 左 2 下 3 右

        // 向上，向左
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 3; k++)
                {
                    if (i > 0)
                        dp[i][j][0][k] = dp[i - 1][j][0][k] + umap[grid[i - 1][j]][k];
                    if (j > 0)
                        dp[i][j][1][k] = dp[i][j - 1][1][k] + umap[grid[i][j - 1]][k];
                };
        // 向右，向下
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                for (int k = 0; k < 3; k++)
                {
                    if (i < m - 1)
                        dp[i][j][2][k] = dp[i + 1][j][2][k] + umap[grid[i + 1][j]][k];
                    if (j < n - 1)
                        dp[i][j][3][k] = dp[i][j + 1][3][k] + umap[grid[i][j + 1]][k];
                }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                // for (int k = 0; k <= 3; k++) {
                ans = max(ans, dp[i][j][0][0] + dp[i][j][1][0] + umap[grid[i][j]][0] +
                                   min(dp[i][j][0][1] + dp[i][j][1][1] + umap[grid[i][j]][1],
                                       dp[i][j][0][2] + dp[i][j][1][2] + umap[grid[i][j]][2]));
                ans = max(ans, dp[i][j][1][0] + dp[i][j][2][0] + umap[grid[i][j]][0] +
                                   min(dp[i][j][1][1] + dp[i][j][2][1] + umap[grid[i][j]][1],
                                       dp[i][j][1][2] + dp[i][j][2][2] + umap[grid[i][j]][2]));
                ans = max(ans, dp[i][j][2][0] + dp[i][j][3][0] + umap[grid[i][j]][0] +
                                   min(dp[i][j][2][1] + dp[i][j][3][1] + umap[grid[i][j]][1],
                                       dp[i][j][2][2] + dp[i][j][3][2] + umap[grid[i][j]][2]));
                ans = max(ans, dp[i][j][3][0] + dp[i][j][0][0] + umap[grid[i][j]][0] +
                                   min(dp[i][j][3][1] + dp[i][j][0][1] + umap[grid[i][j]][1],
                                       dp[i][j][3][2] + dp[i][j][0][2] + umap[grid[i][j]][2]));
            };
        return ans;
    }
};