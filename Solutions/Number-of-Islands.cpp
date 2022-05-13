class Solution {
public:
    void _numIslands(vector<vector<char> >& grid, const int& m, const int& n, const int& x, const int& y) {
        grid[x][y] = '0';
        if (x > 0 && grid[x - 1][y] == '1') _numIslands(grid, m, n, x - 1, y);
        if (x < m - 1 && grid[x + 1][y] == '1') _numIslands(grid, m, n, x + 1, y);
        if (y > 0 && grid[x][y - 1] == '1') _numIslands(grid, m, n, x, y - 1);
        if (y < n - 1 && grid[x][y + 1] == '1') _numIslands(grid, m, n, x, y + 1);
        return;
    };
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    _numIslands(grid, m, n, i, j);
                };
            };
        };
        return ans;
    }
};