class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_map<int, int> rows, columns;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    rows[i] = columns[j] = true;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rows[i] || columns[j])
                    matrix[i][j] = 0;
        return;
    }
};