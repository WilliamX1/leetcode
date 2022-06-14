#include <bits/stdc++.h>

using namespace std;

class Solution
{
  private:
    bool check(vector<vector<int>> &grid, vector<vector<int>> &row_prefix_sum, vector<vector<int>> &col_prefix_sum,
               int start_x, int start_y, int k)
    {
        const int sum =
            row_prefix_sum[start_x][start_y + k - 1] - (start_y == 0 ? 0 : row_prefix_sum[start_x][start_y - 1]);
        for (int i = start_x; i < start_x + k; i++)
        {
            int tmp = row_prefix_sum[i][start_y + k - 1] - (start_y == 0 ? 0 : row_prefix_sum[i][start_y - 1]);
            if (sum != tmp)
                return false;
        };
        for (int j = start_y; j < start_y + k; j++)
        {
            int tmp = col_prefix_sum[start_x + k - 1][j] - (start_x == 0 ? 0 : col_prefix_sum[start_x - 1][j]);
            if (sum != tmp)
                return false;
        };

        int tmp = 0;
        for (int i = 0; i < k; i++)
            tmp += grid[start_x + i][start_y + i];
        if (sum != tmp)
            return false;

        tmp = 0;
        for (int i = 0; i < k; i++)
            tmp += grid[start_x + k - 1 - i][start_y + i];
        if (sum != tmp)
            return false;

        return true;
    };

  public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> row_prefix_sum(m, vector<int>(n, 0));
        vector<vector<int>> col_prefix_sum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    row_prefix_sum[i][j] = grid[i][j];
                else
                    row_prefix_sum[i][j] = row_prefix_sum[i][j - 1] + grid[i][j];

                std::cout << row_prefix_sum[i][j] << ' ';
            };
            std::cout << std::endl;
        };
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (i == 0)
                    col_prefix_sum[i][j] = grid[i][j];
                else
                    col_prefix_sum[i][j] = col_prefix_sum[i - 1][j] + grid[i][j];

                std::cout << col_prefix_sum[i][j] << ' ';
            };
            std::cout << std::endl;
        };

        int ans = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = ans + 1; i + k - 1 < m && j + k - 1 < n; k++)
                {
                    if (check(grid, row_prefix_sum, col_prefix_sum, i, j, k))
                        ans = max(ans, k);
                };
            };
        };
        return ans;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> grid = {{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};
    cout << S.largestMagicSquare(grid);
    return 0;
}