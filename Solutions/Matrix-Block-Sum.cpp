/* 前缀和思想：按行求出前缀和，计算每个元素的时候都根据前缀和按行求出的总和即可 */
/* 测试用例：mat = { 1 2 3      k = 1, ans = { 12, 21, 16
                   4 5 6                     27, 45, 33
                   7 8 9 }                   24, 39, 28}
*/
/* 时间复杂度：O(m * n) 空间复杂度：O(m * n) */

#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size(); /* m = 3, n = 3 */
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        /* prefix = { 1 3 6
                      5 12 21
                      12 27 45 }
        */
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    prefix[i][j] = mat[i][j];
                else if (i == 0)
                    prefix[i][j] = prefix[i][j - 1] + mat[i][j];
                else if (j == 0)
                    prefix[i][j] = prefix[i - 1][j] + mat[i][j];
                else
                    prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i][j];
            };
        };
        vector<vector<int>> answer(m, vector<int>(n, 0));
        /* top_row = 0
           down_row = 1
           left_col = 1
           right_col = 2
         answer = { 12 21
        */
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int top_row = max(0, i - k), down_row = min(m - 1, i + k);
                int left_col = max(0, j - k), right_col = min(n - 1, j + k);
                if (top_row == 0 && left_col == 0)
                    answer[i][j] = prefix[down_row][right_col];
                else if (top_row == 0)
                    answer[i][j] = prefix[down_row][right_col] - prefix[down_row][left_col - 1];
                else if (left_col == 0)
                    answer[i][j] = prefix[down_row][right_col] - prefix[top_row - 1][right_col];
                else
                    answer[i][j] = prefix[down_row][right_col] - prefix[top_row - 1][right_col] -
                                   prefix[down_row][left_col - 1] + prefix[top_row - 1][left_col - 1];
            };
        return answer;
    };
};
