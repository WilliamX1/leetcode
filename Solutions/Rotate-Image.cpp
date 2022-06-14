#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<bool>> flag(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!flag[i][j])
                {
                    swap(matrix[i][j], matrix[j][n - i - 1]);
                    flag[i][j] = flag[j][n - i - 1] = true;
                };
        return;
    }
};