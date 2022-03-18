class Solution {
public:
    int dfs(vector<vector<int>>& grid, const int& m, const int& n, int x, int y) {
        int tot = grid[x][y], add = 0;
        grid[x][y] = 0;
        if (x > 0 && grid[x - 1][y]) add = max(add, dfs(grid, m, n, x - 1, y));
        if (x < m - 1 && grid[x + 1][y]) add = max(add, dfs(grid, m, n, x + 1, y));
        if (y > 0 && grid[x][y - 1]) add = max(add, dfs(grid, m, n, x, y - 1));
        if (y < n - 1 && grid[x][y + 1]) add = max(add, dfs(grid, m, n, x, y + 1));
        grid[x][y] = tot;
        return tot + add;
    };
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) 
                    ans = max(ans, dfs(grid, m, n, i, j));
        return ans;
    }
};