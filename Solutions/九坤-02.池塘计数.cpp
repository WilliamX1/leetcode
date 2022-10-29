class Solution
{
  public:
    void dfs(vector<vector<bool>> &havebeen, const vector<string> &field, const int &m, const int &n, const int &x,
             const int &y)
    {
        havebeen[x][y] = true;
        for (int dx = -1; dx <= 1; dx++)
            for (int dy = -1; dy <= 1; dy++)
            {
                int xx = x + dx, yy = y + dy;
                if (0 <= xx && xx < m && 0 <= yy && yy < n && field[xx][yy] == 'W' && !havebeen[xx][yy])
                    dfs(havebeen, field, m, n, xx, yy);
            }
    };
    int lakeCount(vector<string> &field)
    {
        int m = field.size(), n = field[0].size(), ans = 0;
        vector<vector<bool>> havebeen(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (field[i][j] == 'W' && !havebeen[i][j])
                {
                    ans++;
                    dfs(havebeen, field, m, n, i, j);
                };
        return ans;
    }
};