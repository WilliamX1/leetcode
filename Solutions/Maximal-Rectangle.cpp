#include <vector>

using namespace std;

class Solution
{
  public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();

        int ans = 0;
        vector<vector<int>> row_seq(rows, vector<int>(cols, 0)), col_seq(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (i == 0)
                    col_seq[i][j] = matrix[i][j] == '1';
                else
                    col_seq[i][j] = matrix[i][j] == '1' ? col_seq[i - 1][j] + 1 : 0;
                if (j == 0)
                    row_seq[i][j] = matrix[i][j] == '1';
                else
                    row_seq[i][j] = matrix[i][j] == '1' ? row_seq[i][j - 1] + 1 : 0;

                ans = max(ans, row_seq[i][j]);
                ans = max(ans, col_seq[i][j]);
            };

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(2, 0)));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                int col = 0x7fffffff;
                for (int k = i; k >= 0; k--)
                {
                    if (matrix[k][j] == '0')
                        break;

                    col = min(col, row_seq[k][j]);
                    ans = max(ans, col * (i - k + 1));
                }
            };
        return ans;
    }
};