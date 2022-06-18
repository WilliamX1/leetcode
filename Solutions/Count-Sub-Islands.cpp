class Solution
{
  private:
    static constexpr array<array<int, 2>, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

  public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size(), n = grid1[0].size();

        auto bfs = [&](int sx, int sy) {
            queue<pair<int, int>> q;
            q.emplace(sx, sy);
            grid2[sx][sy] = 0;
            // 判断岛屿包含的每一个格子是否都在 grid1 中出现了
            bool check = grid1[sx][sy];
            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dirs[d][0];
                    int ny = y + dirs[d][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid2[nx][ny] == 1)
                    {
                        q.emplace(nx, ny);
                        grid2[nx][ny] = 0;
                        if (grid1[nx][ny] != 1)
                        {
                            check = false;
                        }
                    }
                }
            }
            return check;
        };

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    ans += bfs(i, j);
                }
            }
        }
        return ans;
    }
};