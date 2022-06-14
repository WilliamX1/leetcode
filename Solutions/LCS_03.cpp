#include <bits/stdc++.h>

using namespace std;

class Solution
{
  private:
    vector<bool> flag;
    vector<vector<int>> arr;
    vector<int> len;
    int dfs(vector<string> &grid, int m, int n, char target, int x, int y, int idx)
    {
        arr[x][y] = idx;
        if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
            flag[idx] = false;
        if ((x > 0 && grid[x - 1][y] == '0') || (x < m - 1 && grid[x + 1][y] == '0') ||
            (y > 0 && grid[x][y - 1] == '0') || (y < n - 1 && grid[x][y + 1] == '0'))
            flag[idx] = false;
        int ans = 1;

        if (x > 0 && arr[x - 1][y] == -1 && grid[x - 1][y] == target)
            ans += dfs(grid, m, n, target, x - 1, y, idx);
        if (x < m - 1 && arr[x + 1][y] == -1 && grid[x + 1][y] == target)
            ans += dfs(grid, m, n, target, x + 1, y, idx);
        if (y > 0 && arr[x][y - 1] == -1 && grid[x][y - 1] == target)
            ans += dfs(grid, m, n, target, x, y - 1, idx);
        if (y < n - 1 && arr[x][y + 1] == -1 && grid[x][y + 1] == target)
            ans += dfs(grid, m, n, target, x, y + 1, idx);
        return ans;
    };

  public:
    int largestArea(vector<string> &grid)
    {
        int m = grid.size(), n = grid[0].size(), idx = 0;
        arr = vector<vector<int>>(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == -1)
                {
                    flag.push_back(true);
                    len.push_back(dfs(grid, m, n, grid[i][j], i, j, idx));
                    idx++;
                };
            };
        int ans = 0;
        for (int i = 0; i < idx; i++)
            if (flag[i])
                ans = max(ans, len[i]);
        return ans;
    }
};