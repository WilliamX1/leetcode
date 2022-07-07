class Solution
{
    class UnionSet
    {
        unordered_map<int, int> father;
        unordered_map<int, int> rank;

      public:
        UnionSet(vector<int> &v)
        {
            for (const int &num : v)
            {
                father[num] = num;
                rank[num] = 1;
            };
        };

        int find(int x)
        {
            return x == father[x] ? x : find(father[x]);
        };

        void to_union(int x, int y)
        {
            int fa_x = find(x), fa_y = find(y);
            if (fa_x == fa_y)
                return;
            else if (rank[fa_x] >= rank[fa_y])
            {
                father[fa_y] = fa_x;
                rank[fa_x] += rank[fa_y];
            }
            else
            {
                father[fa_x] = fa_y;
                rank[fa_y] += rank[fa_x];
            };
        };
    };

    int encode(int x, int y, int n)
    {
        return x * n + y;
    };

    pair<int, int> decode(int xy, int n)
    {
        return make_pair(xy / n, xy % n);
    };

  public:
    void solve(vector<vector<char>> &board)
    {
        vector<int> v;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O')
                    v.push_back(encode(i, j, n));

        UnionSet uni(v);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && i && board[i - 1][j] == 'O')
                    uni.to_union(encode(i, j, n), encode(i - 1, j, n));
                if (board[i][j] == 'O' && j && board[i][j - 1] == 'O')
                    uni.to_union(encode(i, j, n), encode(i, j - 1, n));
            };

        set<int> s;

        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                s.insert(uni.find(encode(i, 0, n)));
            if (board[i][n - 1] == 'O')
                s.insert(uni.find(encode(i, n - 1, n)));
        };

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
                s.insert(uni.find(encode(0, j, n)));
            if (board[m - 1][j] == 'O')
                s.insert(uni.find(encode(m - 1, j, n)));
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!s.count(uni.find(encode(i, j, n))))
                    board[i][j] = 'X';
        return;
    };
};