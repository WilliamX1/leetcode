class Solution
{
  public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = mat.size();
        vector<vector<int>> tmp = mat;

        int maxsize = 4;
        while (maxsize-- > 0)
        {
            bool flag = true;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    tmp[j][n - i - 1] = mat[i][j];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (tmp[i][j] != target[i][j])
                    {
                        flag = false;
                        break;
                    };
            if (flag)
                return true;
            else
                mat = tmp;
        };
        return false;
    }
};