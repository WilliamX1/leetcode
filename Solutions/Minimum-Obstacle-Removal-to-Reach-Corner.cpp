class Solution
{
  public:
    void dfs(const vector<vector<int>> &grid, vector<vector<int>> &visit, set<vector<int>> &st, const int &m,
             const int &n, const int &x, const int &y)
    {
        visit[x][y] = true;
        st.insert({x, y});
        if (x > 0 && !visit[x - 1][y] && !grid[x - 1][y] && !st.count({x - 1, y}))
            dfs(grid, visit, st, m, n, x - 1, y);
        if (x < m - 1 && !visit[x + 1][y] && !grid[x + 1][y] && !st.count({x + 1, y}))
            dfs(grid, visit, st, m, n, x + 1, y);
        if (y > 0 && !visit[x][y - 1] && !grid[x][y - 1] && !st.count({x, y - 1}))
            dfs(grid, visit, st, m, n, x, y - 1);
        if (y < n - 1 && !visit[x][y + 1] && !grid[x][y + 1] && !st.count({x, y + 1}))
            dfs(grid, visit, st, m, n, x, y + 1);
    };
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), step = 0;
        vector<vector<int>> visit(m, vector<int>(n, false));
        vector<vector<int>> v;
        v.push_back({0, 0});
        while (!v.empty())
        {
            set<vector<int>> st;

            for (const vector<int> xy : v)
                if (!st.count({xy[0], xy[1]}))
                    dfs(grid, visit, st, m, n, xy[0], xy[1]);

            vector<vector<int>> next;
            for (const vector<int> xy : st)
            {
                int x = xy[0], y = xy[1];
                // cout << x << ' ' << y << endl;
                if (x == m - 1 && y == n - 1)
                    return step;
                if (x > 0 && !visit[x - 1][y])
                    next.push_back({x - 1, y});
                if (x < m - 1 && !visit[x + 1][y])
                    next.push_back({x + 1, y});
                if (y > 0 && !visit[x][y - 1])
                    next.push_back({x, y - 1});
                if (y < n - 1 && !visit[x][y + 1])
                    next.push_back({x, y + 1});
            };
            step++;
            v = next;
        };
        return -1;
    }
};