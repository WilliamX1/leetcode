#include <deque>
#include <vector>

using namespace std;

class Solution
{
  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int len = grid.size();
        int MAX = len * len + 1;
        vector<vector<int>> dis(len, vector<int>(len, MAX));

        if (grid[0][0] == 1)
            return -1;
        dis[0][0] = 1;

        deque<vector<int>> q;
        q.push_back({0, 0});
        while (!q.empty())
        {
            vector<int> cur = q.front();
            q.pop_front();

            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                {
                    int x = cur[0] + i, y = cur[1] + j;
                    if (x >= 0 && x < len && y >= 0 && y < len && grid[x][y] == 0 &&
                        dis[cur[0]][cur[1]] + 1 < dis[x][y])
                    {
                        dis[x][y] = dis[cur[0]][cur[1]] + 1;
                        q.push_back({x, y});
                    };
                };
        };
        return dis[len - 1][len - 1] == MAX ? -1 : dis[len - 1][len - 1];
    };
};