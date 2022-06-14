#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row_min(m, 0x7fffffff);
        vector<int> col_max(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                row_min[i] = min(row_min[i], matrix[i][j]);
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++)
                col_max[j] = max(col_max[j], matrix[i][j]);
        vector<int> ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (row_min[i] == matrix[i][j] && col_max[j] == matrix[i][j])
                    ans.push_back(matrix[i][j]);
        return ans;
    }
};