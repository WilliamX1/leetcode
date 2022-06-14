#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
  public:
    vector<int> parent;
    vector<int> size;
    int n;
    /* 当前连通分量个数 */
    int setCount;

  public:
    UnionFind(int _n) : parent(_n), size(_n, 1), n(_n), setCount(_n)
    {
        iota(parent.begin(), parent.end(), 0);
    };
    int findset(int x)
    {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    };
    bool unite(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        if (x == y)
            return false;
        // if (size[x] < size[y]) swap(x, y);

        parent[y] = x;
        // size[x] += size[y];
        --setCount;
        return true;
    };
    int connected(int x, int y)
    {
        x = parent[x];
        y = parent[y];
        return x == y;
    }
};
class Solution
{
  public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int m = points.size();
        int n = (m * (m - 1)) / 2;
        vector<vector<int>> edges(n);
        /* 构造边集合 */
        int idx = 0;
        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < m; j++)
            {
                /* edges[idx] = idx1, idx2, dis */
                /* idx =         0     1     2  */
                edges[idx++] = {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
            }
        sort(edges.begin(), edges.end(), [](const auto &u, const auto &v) { return u[2] < v[2]; });

        UnionFind uf_std(m);
        int value = 0;
        for (int i = 0; i < n; i++)
        {
            if (uf_std.unite(edges[i][0], edges[i][1]))
            {
                value += edges[i][2];
            };
            if (uf_std.setCount == 1)
                break; // 提前结束
        };
        return value;
    }
};

int main()
{
    vector<vector<int>> v = {{2, -3}, {-17, -8}, {13, 8}, {-17, -15}};
    Solution S;
    S.minCostConnectPoints(v);
    return 0;
}