class Solution
{
  private:
    int ans = 0;
    void movingCount(int m, int n, int k, int x, int y, vector<vector<bool>> &flags)
    {
        int acc = 0;
        int xx = x, yy = y;
        while (xx > 0)
        {
            acc += xx % 10;
            xx /= 10;
        };
        while (yy > 0)
        {
            acc += yy % 10;
            yy /= 10;
        };
        if (acc <= k)
        {
            flags[x][y] = true;
            ans++;
            if (x > 0 && flags[x - 1][y] == false)
                movingCount(m, n, k, x - 1, y, flags);
            if (x < m - 1 && flags[x + 1][y] == false)
                movingCount(m, n, k, x + 1, y, flags);
            if (y > 0 && flags[x][y - 1] == false)
                movingCount(m, n, k, x, y - 1, flags);
            if (y < n - 1 && flags[x][y + 1] == false)
                movingCount(m, n, k, x, y + 1, flags);
        };
        return;
    };

  public:
    int movingCount(int m, int n, int k)
    {
        vector<vector<bool>> flags(m, vector<bool>(n, false));
        movingCount(m, n, k, 0, 0, flags);
        return ans;
    }
};