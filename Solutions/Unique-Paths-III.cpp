class Solution {
public:
    int dfs(const vector<vector<int>>& grid, int m, int n, int x, int y, int tot, vector<vector<bool>> havebeen) {
        havebeen[x][y] = true;
        tot--;
        if (grid[x][y] == 2) return tot == 0;
        else {
            int ans = 0;
            if (x > 0 && havebeen[x - 1][y] == false && grid[x - 1][y] >= 0) ans += dfs(grid, m, n, x - 1, y, tot, havebeen);
            if (x < m - 1 && havebeen[x + 1][y] == false && grid[x + 1][y] >= 0) ans += dfs(grid, m, n, x + 1, y, tot, havebeen);
            if (y > 0 && havebeen[x][y - 1] == false && grid[x][y - 1] >= 0) ans += dfs(grid, m, n, x, y - 1, tot, havebeen);
            if (y < n - 1 && havebeen[x][y + 1] == false && grid[x][y + 1] >= 0) ans += dfs(grid, m, n, x, y + 1, tot, havebeen);
            return ans;
        };
    };
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x = -1, y = -1, m = grid.size(), n = grid[0].size(), t = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    break;
                } else if (grid[i][j] == -1) t++;
        vector<vector<bool>> havebeen(m, vector<bool>(n, false));
        return dfs(grid, m, n, x, y, m * n - t, havebeen);
    }
};