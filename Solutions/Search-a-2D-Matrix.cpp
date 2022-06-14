class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0;
        while (row < m && matrix[row][0] <= target)
            row++;
        row--;
        if (row < 0)
            return false;

        int column = upper_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin() - 1;
        return matrix[row][column] == target;
    }
};