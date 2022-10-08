class Solution
{
  public:
    vector<vector<int>> sandyLandManagement(int size)
    {
        vector<vector<bool>> v(size + 1, vector<bool>(2 * size, 0));
        int left = true;
        set<vector<int>> ans;

        for (int j = 1; j < 2 * size; j += 2)
            ans.insert({size, j});
        for (int j = 1; j < 2 * size; j++)
            v[size][j] = true;

        for (int i = size - 1; i >= 1; i--)
        {

            for (int j = 1; j < 2 * i; j++)
            {
                // cout << i << ' ' << j << ' ' << v[4][7] << endl;
                if (v[i][j])
                    continue;
                else if (j & 1) // 奇数，向下
                {
                    int tmpcnt = (j > 0 && v[i][j - 1]) + (j < 2 * size - 1 && v[i][j + 1]) + v[i + 1][j];
                    if (tmpcnt >= 2)
                        v[i][j] = true;
                    else if (j == 1 || j == 2 * size - 1)
                    {
                        if (!v[i + 1][j + 1])
                        {
                            v[i][j] = true;
                            ans.insert({i, j});
                        }
                    }
                    else
                    {
                        cout << "impossible" << endl;
                    }
                }
                else
                {
                    int tmpcnt = (j > 0 && v[i][j - 1]) + (j < 2 * size - 1 && v[i][j + 1]) +
                                 (i > 0 && j > 0 && v[i - 1][j - 1]);
                    // cout << i << ' ' << j << ' ' << tmpcnt << ' ' << (j > 0 && v[i][j - 1]) << ' '
                    //      << (j < 2 * size - 1 && v[i][j + 1]) << ' ' << (i > 0 && j > 0 && v[i - 1][j - 1]) << endl;
                    if (tmpcnt >= 2)
                        v[i][j] = true;
                    else if (tmpcnt == 1)
                    {
                        v[i - 1][j - 1] = v[i][j] = true;
                        ans.insert({i - 1, j - 1});
                    }
                    else if (tmpcnt == 0)
                    {
                        v[i][j] = true;
                        ans.insert({i, j});
                    };
                };
            }
        };

        ans.insert({1, 1});

        vector<vector<int>> ret;
        for (const vector<int> v : ans)
            ret.push_back(v);

        sort(ret.begin(), ret.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        return ret;
    };
};