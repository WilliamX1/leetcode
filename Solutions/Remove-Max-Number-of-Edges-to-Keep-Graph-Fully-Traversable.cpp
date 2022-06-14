#include <bits/stdc++.h>

using namespace std;

/* 并查集 */
class UnionFind
{
  public:
    vector<int> parent;
    vector<int> size;
    int n;
    /* 当前连通分量数目 */
    int setCount;

  public:
    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int findset(int x)
    {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }
    bool unite(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        if (x == y)
            return false;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    bool connected(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

class Solution
{
  public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        int res = 0;

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] > b[0]; });
        /* edges[i] = [typei, ui, vi] */
        // 类型 1：只能由 Alice 遍历。
        // 类型 2：只能由 Bob 遍历。
        // 类型 3：Alice 和 Bob 都可以遍历。
        /* 对Alice */
        UnionFind uf_Alice(n + 1);
        set<int> uf_Alice_surplus;

        for (int i = 0; i < m; i++)
        {
            switch (edges[i][0])
            {
            case 1:
                if (!uf_Alice.unite(edges[i][1], edges[i][2]))
                    res++;
                break;
            case 2:
                break;
            case 3:
                if (!uf_Alice.unite(edges[i][1], edges[i][2]))
                    uf_Alice_surplus.insert(i);
                break;
            default:
                break;
            }
        }
        if (uf_Alice.setCount != 2)
            return -1;
        /* 对Bob */
        UnionFind uf_Bob(n + 1);
        set<int> uf_Bob_surplus;

        for (int i = 0; i < m; i++)
        {
            switch (edges[i][0])
            {
            case 1:
                break;
            case 2:
                if (!uf_Bob.unite(edges[i][1], edges[i][2]))
                    res++;
                break;
            case 3:
                if (!uf_Bob.unite(edges[i][1], edges[i][2]))
                    uf_Bob_surplus.insert(i);
                break;
            default:
                break;
            }
        };
        if (uf_Bob.setCount != 2)
            return -1;

        /* 寻找交叉 */
        auto iter = uf_Bob_surplus.begin();
        while (iter != uf_Bob_surplus.end())
        {
            if (uf_Alice_surplus.find(*iter) != uf_Alice_surplus.end())
                res++;
            iter++;
        };
        return res;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 1, 2}, {2, 1, 2}, {3, 1, 2}};
    Solution S;
    cout << S.maxNumEdgesToRemove(2, v);
    return 0;
}