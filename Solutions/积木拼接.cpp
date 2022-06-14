class Solution
{
  public:
    const int NN = 6;
    int n;
    const vector<int> choice = {0, 1, 2, 90, 180, 270};
    bool OK_X(const vector<string> &shape, vector<vector<vector<bool>>> &have, const int &x, const int &ch)
    {
        for (int y = 0; y < n; y++)
        {
            for (int z = 0; z < n; z++)
            {
                int yy, zz;
                if (ch == 0)
                {
                    yy = y;
                    zz = z;
                }
                else if (ch == 1)
                { // left-right
                    yy = n - y - 1;
                    zz = z;
                }
                else if (ch == 2)
                { // up-down
                    yy = y;
                    zz = n - z - 1;
                }
                else if (ch == 90)
                {
                    yy = z, zz = n - y - 1;
                }
                else if (ch == 180)
                {
                    yy = n - y - 1, zz = n - z - 1;
                }
                else if (ch == 270)
                {
                    yy = n - z - 1, zz = y;
                };
                if (shape[y][z] == '1')
                {
                    if (have[x][yy][zz])
                        return false;
                    have[x][yy][zz] = true;
                };
            };
        };
        return true;
    };
    bool OK_Y(const vector<string> &shape, vector<vector<vector<bool>>> &have, const int &y, const int &ch)
    {
        for (int x = 0; x < n; x++)
        {
            for (int z = 0; z < n; z++)
            {
                int xx, zz;
                if (ch == 0)
                {
                    xx = x;
                    zz = z;
                }
                else if (ch == 1)
                { // left-right
                    xx = n - x - 1;
                    zz = z;
                }
                else if (ch == 2)
                { // up-down
                    xx = x;
                    zz = n - z - 1;
                }
                else if (ch == 90)
                {
                    xx = z, zz = n - x - 1;
                }
                else if (ch == 180)
                {
                    xx = n - x - 1, zz = n - z - 1;
                }
                else if (ch == 270)
                {
                    xx = n - z - 1, zz = x;
                };
                if (shape[x][z] == '1')
                {
                    if (have[xx][y][zz])
                        return false;
                    have[xx][y][zz] = true;
                };
            };
        };
        return true;
    };
    bool OK_Z(const vector<string> &shape, vector<vector<vector<bool>>> &have, const int &z, const int &ch)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                int xx, yy;
                if (ch == 0)
                {
                    xx = x;
                    yy = y;
                }
                else if (ch == 1)
                { // left-right
                    xx = n - x - 1;
                    yy = y;
                }
                else if (ch == 2)
                { // up-down
                    xx = x;
                    yy = n - y - 1;
                }
                else if (ch == 90)
                {
                    xx = y, yy = n - x - 1;
                }
                else if (ch == 180)
                {
                    xx = n - x - 1, yy = n - y - 1;
                }
                else if (ch == 270)
                {
                    xx = n - y - 1, yy = x;
                };
                if (shape[x][y] == '1')
                {
                    if (have[xx][yy][z])
                        return false;
                    have[xx][yy][z] = true;
                };
            };
        };
        return true;
    };
    bool dfs(const vector<vector<string>> &shapes, const int &index, const vector<vector<vector<bool>>> &havebeen)
    {
        // x = 0/1/2... , y & z 平面
        // cout << index << endl;
        if (index == NN)
            return true;

        vector<vector<vector<bool>>> have;
        int x = 0;
        for (const int &ch : choice)
        {
            have = havebeen;
            if (OK_X(shapes[index], have, x, ch) && dfs(shapes, index + 1, have))
                return true;
        };
        x = n - 1;
        for (const int &ch : choice)
        {
            have = havebeen;
            if (OK_X(shapes[index], have, x, ch) && dfs(shapes, index + 1, have))
                return true;
        };

        // y = 0/1/2... , x & z 平面
        int y = 0;
        for (const int &ch : choice)
        {
            have = havebeen;
            if (OK_Y(shapes[index], have, y, ch) && dfs(shapes, index + 1, have))
                return true;
        };
        y = n - 1;
        for (const int &ch : choice)
        {
            have = havebeen;
            if (OK_Y(shapes[index], have, y, ch) && dfs(shapes, index + 1, have))
                return true;
        };

        // z = 0/1/2... , x & y 平面
        int z = 0;
        for (const int &ch : choice)
        {
            have = havebeen;
            if (OK_Z(shapes[index], have, z, ch) && dfs(shapes, index + 1, have))
                return true;
        };
        z = n - 1;
        for (const int &ch : choice)
        {
            have = havebeen;
            if (OK_Z(shapes[index], have, z, ch) && dfs(shapes, index + 1, have))
                return true;
        };

        return false;
    };
    bool composeCube(vector<vector<string>> &shapes)
    {
        n = shapes[0].size();
        int tot = 0;
        for (const vector<string> &shape : shapes)
        {
            for (const string &str : shape)
            {
                for (const char &ch : str)
                {
                    tot += ch == '1';
                };
            };
        };
        // if (tot != ) return false;

        vector<vector<vector<bool>>> havebeen(n, vector<vector<bool>>(n, vector<bool>(n, false)));
        return dfs(shapes, 0, havebeen);
    }
};