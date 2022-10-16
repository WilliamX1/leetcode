class Solution
{
  public:
    int componentValue(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size(), target;
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        };

        vector<int> weight(n);
        function<void(int, int)> dfs1 = [&](int sn, int fa) {
            weight[sn] = nums[sn];
            for (int fn : g[sn])
                if (fn != fa)
                {
                    dfs1(fn, sn);
                    weight[sn] += weight[fn];
                };
        };
        dfs1(0, -1);

        function<bool(int, int, int)> dfs2 = [&](int sn, int fa, int X) {
            int sm = nums[sn];
            for (int fn : g[sn])
                if (fn != fa)
                {
                    if (!dfs2(fn, sn, X))
                        return false;
                    if (weight[fn] % X != 0)
                        sm += weight[fn] % X;
                };
            return sm <= X ? true : false;
        };

        for (int i = 1; i <= weight[0]; i++)
            if (weight[0] % i == 0 && dfs2(0, -1, i))
                return weight[0] / i - 1;
        return 0;
    }
};