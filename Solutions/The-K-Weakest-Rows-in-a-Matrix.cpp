class Solution
{
  public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        vector<bool> flag(m, 0);
        vector<int> ans;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (flag[i])
                    continue;
                if (!mat[i][j])
                {
                    k--;
                    flag[i] = true;
                    ans.push_back(i);
                    if (!k)
                        return ans;
                };
            }
        };
        for (int i = 0; i < m; i++)
        {
            if (!flag[i])
            {
                k--;
                flag[i] = true;
                ans.push_back(i);
            }
            if (!k)
                break;
        }
        return ans;
    }
};