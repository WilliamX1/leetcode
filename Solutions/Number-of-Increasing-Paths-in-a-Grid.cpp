class Solution
{
  public:
    struct node
    {
        int x;
        int y;
        int val;
        node(){};
        node(int x, int y, int val) : x(x), y(y), val(val){};
    };

    int countPaths(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<node> v;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                v.emplace_back(i, j, grid[i][j]);

        sort(v.begin(), v.end(), [](const node &a, const node &b) { return a.val < b.val; });

        vector<vector<int>> vals(m, vector<int>(n, 1));
        int ans = 0, mod = 1e9 + 7;
        for (const node &nn : v)
        {
            int x = nn.x, y = nn.y, val = nn.val;
            if (x > 0 && grid[x - 1][y] < grid[x][y])
                vals[x][y] = (vals[x][y] + vals[x - 1][y]) % mod;
            if (x < m - 1 && grid[x + 1][y] < grid[x][y])
                vals[x][y] = (vals[x][y] + vals[x + 1][y]) % mod;
            if (y > 0 && grid[x][y - 1] < grid[x][y])
                vals[x][y] = (vals[x][y] + vals[x][y - 1]) % mod;
            if (y < n - 1 && grid[x][y + 1] < grid[x][y])
                vals[x][y] = (vals[x][y] + vals[x][y + 1]) % mod;
            // cout << "x: " << x << " y: " << y << " val: " << vals[x][y] << endl;
            ans = (ans + vals[x][y]) % mod;
        };
        return ans;
    }
};