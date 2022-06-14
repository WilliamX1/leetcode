class UF
{
  public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;

  public:
    UF(int n) : n(n), comp_cnt(n), fa(n), sz(n, 1)
    {
        iota(fa.begin(), fa.end(), 0);
    };

    int findset(int x)
    {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    };

    bool unite(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        if (x == y)
        {
            return false;
        };
        if (sz[x] < sz[y])
        {
            swap(x, y);
        };
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
        return true;
    };

    bool connected(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        return x == y;
    };
};

class Solution
{
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        vector<int> qid(queries.size());
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(), [&](int i, int j) { return queries[i][2] < queries[j][2]; });

        sort(edgeList.begin(), edgeList.end(), [](const auto &e1, const auto &e2) { return e1[2] < e2[2]; });

        UF uf(n);
        int i = 0;
        vector<bool> ans(queries.size());
        for (int query : qid)
        {
            while (i < edgeList.size() && edgeList[i][2] < queries[query][2])
            {
                uf.unite(edgeList[i][0], edgeList[i][1]);
                ++i;
            };
            ans[query] = uf.connected(queries[query][0], queries[query][1]);
        };
        return ans;
    }
};