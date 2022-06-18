class Solution
{
    static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, 0x7fffffff));
        deque<pair<int, int>> dq;
        dq.emplace_back(0, 0);
        dis[0][0] = 0;
        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto &[dx, dy] : dirs)
            {
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < m && 0 <= ny && ny < n)
                {
                    int g = grid[nx][ny];
                    if (dis[x][y] + g < dis[nx][ny])
                    {
                        dis[nx][ny] = dis[x][y] + g;
                        dq.emplace_back(nx, ny);
                    };
                };
            };
        };
        return dis[m - 1][n - 1];
    }
};