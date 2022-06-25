#include <vector>
class Solution
{
    class DisjSet
    {
      private:
        std::vector<int> parent;
        std::vector<int> rank; // 秩

      public:
        DisjSet(int max_size) : parent(std::vector<int>(max_size)), rank(std::vector<int>(max_size, 0))
        {
            for (int i = 0; i < max_size; ++i)
                parent[i] = i;
        }
        int find(int x)
        {
            return x == parent[x] ? x : (parent[x] = find(parent[x]));
        }
        void to_union(int x1, int x2)
        {
            int f1 = find(x1);
            int f2 = find(x2);
            if (rank[f1] > rank[f2])
                parent[f2] = f1;
            else
            {
                parent[f1] = f2;
                if (rank[f1] == rank[f2])
                    ++rank[f2];
            }
        }
        bool is_same(int e1, int e2)
        {
            return find(e1) == find(e2);
        };
    };

  public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        DisjSet D(n);
        for (const vector<int> &edge : edges)
            D.to_union(edge[0], edge[1]);

        unordered_map<int, int> p;
        for (int i = 0; i < n; i++)
            p[D.find(i)]++;
        long long ans = 0;
        for (auto &[u, v] : p)
        {
            ans += (long long)(n - v) * (long long)v;
        };
        ans /= 2;
        return ans;
    }
};