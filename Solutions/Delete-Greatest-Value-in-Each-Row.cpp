class Solution
{
  public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int cnt = 0; cnt < n; cnt++)
        {
            int M = 0;
            for (int i = 0; i < m; i++)
            {
                int idx = max_element(grid[i].begin(), grid[i].end()) - grid[i].begin();
                M = max(M, grid[i][idx]);
                grid[i][idx] = 0;
            };
            ans += M;
        };
        return ans;
    }
};