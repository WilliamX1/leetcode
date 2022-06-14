class Solution
{
  public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] < 0)
                    ans++;
        return ans;
    }
};