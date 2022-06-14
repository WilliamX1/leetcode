class Solution
{
  public:
    const int mod = 1e9 + 7;
    int dfs(const vector<string> &pizza, const vector<vector<int>> &flowers, const int &flower,
            vector<vector<vector<int>>> &dp, const int k, const int &x, const int &y, const int &row, const int &col)
    {
        // cout << "x: " << x << " y: " << y << "k: " << k << endl;
        if (k == 1)
        {
            int ans = flowers[x][y];
            return ans > 0;
        };
        if (dp[x][y][k] == -1)
            dp[x][y][k]++;

        for (int i = x + 1; i < row; i++)
        {
            int f = flowers[x][y] - flowers[i][y];
            if (f > 0 && flower - f >= k - 1)
            {
                if (dp[i][y][k - 1] == -1)
                    dp[i][y][k - 1] = dfs(pizza, flowers, flower - f, dp, k - 1, i, y, row, col);
                dp[x][y][k] += dp[i][y][k - 1];
                dp[x][y][k] %= mod;
            };
        };
        for (int j = y + 1; j < col; j++)
        {
            int f = flowers[x][y] - flowers[x][j];
            if (f > 0 && flower - f >= k - 1)
            {
                if (dp[x][j][k - 1] == -1)
                    dp[x][j][k - 1] = dfs(pizza, flowers, flower - f, dp, k - 1, x, j, row, col);
                dp[x][y][k] += dp[x][j][k - 1];
                dp[x][y][k] %= mod;
            };
        };
        return dp[x][y][k];
    };
    int ways(vector<string> &pizza, int k)
    {
        int row = pizza.size(), col = pizza[0].size(), flower = 0;
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(k + 1, -1)));
        vector<vector<int>> flowers(row, vector<int>(col, 0));
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = col - 1; j >= 0; j--)
            {
                flower += pizza[i][j] == 'A';
                if (i == row - 1 && j == col - 1)
                    flowers[i][j] = pizza[i][j] == 'A';
                else if (i == row - 1)
                    flowers[i][j] = flowers[i][j + 1] + (pizza[i][j] == 'A');
                else if (j == col - 1)
                    flowers[i][j] = flowers[i + 1][j] + (pizza[i][j] == 'A');
                else
                    flowers[i][j] =
                        flowers[i][j + 1] + flowers[i + 1][j] - flowers[i + 1][j + 1] + (pizza[i][j] == 'A');
            };
        };
        // cout << "Init" << endl;
        return dfs(pizza, flowers, flower, dp, k, 0, 0, row, col);
    }
};