class Solution
{
  public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < n - 1; j++)
                for (int k1 = -1; k1 <= 1; k1++)
                    for (int k2 = -1; k2 <= 1; k2++)
                        ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + k1][j + k2]);

        return ans;
    }
};