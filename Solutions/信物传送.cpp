class Solution
{
  public:
    void dfs(const vector<string> &matrix, const int &m, const int &n, const int &end_x, const int &end_y, int x, int y,
             vector<vector<int>> &dis)
    {
        if (dis[x][y] >= dis[end_x][end_y])
            return;
        if (x - 1 >= 0)
        { // 向上
            if (matrix[x][y] == '^' && dis[x][y] < dis[x - 1][y] ||
                matrix[x][y] != '^' && dis[x][y] + 1 < dis[x - 1][y])
            {
                dis[x - 1][y] = dis[x][y] + (matrix[x][y] != '^');
                dfs(matrix, m, n, end_x, end_y, x - 1, y, dis);
            };
        };
        if (x + 1 < m)
        { // 向下
            if (matrix[x][y] == 'v' && dis[x][y] < dis[x + 1][y] ||
                matrix[x][y] != 'v' && dis[x][y] + 1 < dis[x + 1][y])
            {
                dis[x + 1][y] = dis[x][y] + (matrix[x][y] != 'v');
                dfs(matrix, m, n, end_x, end_y, x + 1, y, dis);
            };
        };
        if (y - 1 >= 0)
        { // 向左
            if (matrix[x][y] == '<' && dis[x][y] < dis[x][y - 1] ||
                matrix[x][y] != '<' && dis[x][y] + 1 < dis[x][y - 1])
            {
                dis[x][y - 1] = dis[x][y] + (matrix[x][y] != '<');
                dfs(matrix, m, n, end_x, end_y, x, y - 1, dis);
            };
        };
        if (y + 1 < n)
        { // 向右
            if (matrix[x][y] == '>' && dis[x][y] < dis[x][y + 1] ||
                matrix[x][y] != '>' && dis[x][y] + 1 < dis[x][y + 1])
            {
                dis[x][y + 1] = dis[x][y] + (matrix[x][y] != '>');
                dfs(matrix, m, n, end_x, end_y, x, y + 1, dis);
            };
        };
    };
    int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dis(m, vector<int>(n, 1e9 + 7));
        dis[start[0]][start[1]] = 0;
        dfs(matrix, m, n, end[0], end[1], start[0], start[1], dis);
        return dis[end[0]][end[1]];
    };
};