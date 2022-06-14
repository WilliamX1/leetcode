class Solution
{
  public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int count = 0, n = matrix.size(), negm = 0, negM = -1e9, posm = 1e9, posM = 0;
        long long tot = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] < 0)
                {
                    negm = min(negm, matrix[i][j]);
                    negM = max(negM, matrix[i][j]);
                    count++;
                }
                else
                {
                    posm = min(posm, matrix[i][j]);
                    posM = max(posM, matrix[i][j]);
                }
                tot += (long long)abs(matrix[i][j]);
            }
        }
        if (count & 1)
            tot += (long long)2 * max(negM, -posm);
        return tot;
    }
};