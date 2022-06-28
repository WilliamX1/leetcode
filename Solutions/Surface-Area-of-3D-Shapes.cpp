class Solution
{
  public:
    const vector<vector<int>> pos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int surfaceArea(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += grid[i][j] * 6 - 2 * max(0, grid[i][j] - 1);
                for (const vector<int> &p : pos)
                {
                    int x = i + p[0], y = j + p[1];
                    if (0 <= x && x < n && 0 <= y && y < m)
                        ans -= min(grid[i][j], grid[x][y]);
                };
            };
        };
        return ans;
    }
};