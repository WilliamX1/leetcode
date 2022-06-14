class Solution
{
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int cnt = 0, tot = 0;
                for (int x = -1; x <= 1; x++)
                    for (int y = -1; y <= 1; y++)
                        if (0 <= i + x && i + x < m && 0 <= j + y && j + y < n)
                        {
                            cnt++;
                            tot += img[i + x][j + y];
                        };
                ans[i][j] = tot / cnt;
            };
        return ans;
    }
};