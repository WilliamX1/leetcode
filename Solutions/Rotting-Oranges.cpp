class Solution
{
  public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        deque<pair<int, int>> dque;
        int m = grid.size(), n = grid[0].size(), tt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    dque.emplace_back(i * n + j, 0);
                tt += !!grid[i][j];
            };
        int ans = 0;

        const vector<vector<int>> position = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!dque.empty())
        {
            pair<int, int> p = dque.front();
            dque.pop_front();
            tt--;

            int x = p.first / n, y = p.first % n, time = p.second;
            // cout << "x: " << x << " y: " << y << " time: " << time << endl;
            ans = max(ans, time);
            for (const vector<int> &pos : position)
                if (0 <= x + pos[0] && x + pos[0] < m && 0 <= y + pos[1] && y + pos[1] < n &&
                    grid[x + pos[0]][y + pos[1]] == 1)
                {
                    dque.emplace_back((x + pos[0]) * n + (y + pos[1]), time + 1);
                    grid[x + pos[0]][y + pos[1]] = 2;
                };
        };
        return tt ? -1 : ans;
    }
};