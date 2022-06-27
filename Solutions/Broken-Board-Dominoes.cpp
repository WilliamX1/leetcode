class Solution
{
  public:
    void _domino(int x, int y, const int &n, const int &m, vector<vector<bool>> &havebeen, int cnt, int &ret)
    {
        if (y >= m)
        {
            ++x;
            y = 0;
        };
        if (x >= n)
        {
            ret = max(ret, cnt);
            return;
        };
        if (((n - x - 1) * m + m - y) / 2 + cnt <= ret)
            return;
        if (!havebeen[x][y])
        {
            bool f1 = false, f2 = false;
            if (y + 1 < m && !havebeen[x][y + 1])
            {
                f1 = true;
                havebeen[x][y] = havebeen[x][y + 1] = true;
                _domino(x, y + 2, n, m, havebeen, cnt + 1, ret);
                havebeen[x][y] = havebeen[x][y + 1] = false;
            };
            if (x + 1 < n && !havebeen[x + 1][y])
            {
                f2 = true;
                havebeen[x][y] = havebeen[x + 1][y] = true;
                _domino(x, y + 1, n, m, havebeen, cnt + 1, ret);
                havebeen[x][y] = havebeen[x + 1][y] = false;
            };

            if (!f1 && !f2)
                _domino(x, y + 1, n, m, havebeen, cnt, ret);
        }
        else
            _domino(x, y + 1, n, m, havebeen, cnt, ret);
        return;
    }
    int domino(int n, int m, vector<vector<int>> &broken)
    {
        vector<vector<bool>> havebeen(n, vector<bool>(m, false));
        for (const vector<int> &v : broken)
            havebeen[v[0]][v[1]] = true;
        int cnt = 0, ret = 0;
        _domino(0, 0, n, m, havebeen, cnt, ret);
        return ret;
    }
};