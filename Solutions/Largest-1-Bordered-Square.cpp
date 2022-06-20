class Solution
{
  public:
    bool exists(const vector<vector<int>> &grid, const vector<vector<int>> &leftRightPrefix,
                const vector<vector<int>> &upDownPrefix, const int &n, const int &m, const int &cc)
    {
        for (int i = 0; i + cc <= n; i++)
        {
            for (int j = 0; j + cc <= m; j++)
            {
                if (leftRightPrefix[i][j + cc - 1] - leftRightPrefix[i][j] + grid[i][j] == cc &&
                    leftRightPrefix[i + cc - 1][j + cc - 1] - leftRightPrefix[i + cc - 1][j] + grid[i + cc - 1][j] ==
                        cc &&
                    upDownPrefix[i + cc - 1][j] - upDownPrefix[i][j] + grid[i][j] == cc &&
                    upDownPrefix[i + cc - 1][j + cc - 1] - upDownPrefix[i][j + cc - 1] + grid[i][j + cc - 1] == cc)
                {
                    return true;
                };
            };
        };
        return false;
    };
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> leftRightPrefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            leftRightPrefix[i][0] = grid[i][0];
            for (int j = 1; j < m; j++)
            {
                leftRightPrefix[i][j] = leftRightPrefix[i][j - 1] + grid[i][j];
            };
        };
        vector<vector<int>> upDownPrefix(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            upDownPrefix[0][j] = grid[0][j];
            for (int i = 1; i < n; i++)
            {
                upDownPrefix[i][j] = upDownPrefix[i - 1][j] + grid[i][j];
            };
        };

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << leftRightPrefix[i][j] << ' ';
        //     };
        //     cout << endl;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << upDownPrefix[i][j] << ' ';
        //     };
        //     cout << endl;
        // }

        for (int p = min(n, m); p >= 1; p--)
            if (exists(grid, leftRightPrefix, upDownPrefix, n, m, p))
                return p * p;
        return 0;
    }
};