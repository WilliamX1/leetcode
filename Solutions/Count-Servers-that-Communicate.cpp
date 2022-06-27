class Solution
{
  public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m, 0), colomns(n, 0);
        for (int i = 0; i < m; i++)
            rows[i] = accumulate(grid[i].begin(), grid[i].end(), 0);
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                colomns[j] += grid[i][j];
            };
        };
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] && ((rows[i] > 1) || colomns[j] > 1))
                    ans++;
            };
        return ans;
    }
};