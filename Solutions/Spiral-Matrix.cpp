class Solution
{
  public:
    void getNext(int &i, int &j, int &dir, const vector<vector<bool>> &evergo)
    {
        switch (dir)
        {
        case 1: // 向右
            if (evergo[i + 1][j + 1 + 1] == true)
            {
                dir = 2;
                i++;
            }
            else
                j++;
            break;
        case 2: // 向下
            if (evergo[i + 1 + 1][j + 1] == true)
            {
                dir = 3;
                j--;
            }
            else
                i++;
            break;
        case 3: // 向左
            if (evergo[i + 1][j - 1 + 1] == true)
            {
                dir = 4;
                i--;
            }
            else
                j--;
            break;
        case 4: // 向上
            if (evergo[i - 1 + 1][j + 1] == true)
            {
                dir = 1;
                j++;
            }
            else
                i--;
            break;
        default:
            break;
        };
        return;
    };
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int i = 0, j = 0, m = matrix.size(), n = matrix[0].size(), len = m * n, dir = 1;
        vector<vector<bool>> evergo(m + 2, vector<bool>(n + 2, false));
        for (int k = 0; k <= m + 1; k++)
            evergo[k][0] = evergo[k][n + 1] = true;
        for (int k = 0; k <= n + 1; k++)
            evergo[0][k] = evergo[m + 1][k] = true;
        vector<int> v;
        while (len-- > 0)
        {
            v.push_back(matrix[i][j]);
            evergo[i + 1][j + 1] = true;
            getNext(i, j, dir, evergo);
        };
        return v;
    }
};