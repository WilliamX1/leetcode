class Solution
{
  public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            int x = i, y = 0, idx = 0;
            vector<int> v;
            while (x < m && y < n)
                v.push_back(mat[x++][y++]);
            sort(v.begin(), v.end(), less<int>());
            x = i, y = 0;
            while (x < m && y < n)
                mat[x++][y++] = v[idx++];
        };
        for (int j = 1; j < n; j++)
        {
            int x = 0, y = j, idx = 0;
            vector<int> v;
            while (x < m && y < n)
                v.push_back(mat[x++][y++]);
            sort(v.begin(), v.end(), less<int>());
            x = 0, y = j;
            while (x < m && y < n)
                mat[x++][y++] = v[idx++];
        };
        return mat;
    }
};