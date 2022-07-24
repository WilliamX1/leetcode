class Solution
{
  public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int ptr = 0;
                while (ptr < n && grid[i][ptr] == grid[ptr][j])
                    ptr++;
                ans += ptr == n;
            };
        return ans;
    }
};