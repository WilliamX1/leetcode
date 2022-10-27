class Solution
{
  public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> v(m);

        int ans = 0;
        for (int i = 0; i < 1 << n; i++)
        {
            if (__builtin_popcount(i) == numSelect)
            {
                int tmp = 0;
                for (int j = 0; j < m; j++)
                {
                    bool flag = true;
                    for (int k = 0; k < n; k++)
                    {
                        if (matrix[j][k])
                            if ((i >> k) & 1)
                                continue;
                            else
                            {
                                flag = false;
                                break;
                            };
                    };
                    tmp += flag;
                };
                ans = max(ans, tmp);
            };
        };
        return ans;
    }
};