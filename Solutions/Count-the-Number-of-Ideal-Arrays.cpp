class Solution
{
  public:
    int64_t mod = 1e9 + 7;
    int64_t Pow(int64_t a, int64_t b, int64_t mod)
    {
        int64_t ans = 1;
        while (b)
        {
            if (b & 1)
                ans = (ans * a) % mod;
            b /= 2;
            a = (a * a) % mod;
        }
        return ans;
    }
    int64_t C(int64_t n, int64_t m)
    {
        if (n < m)
            return 0;
        int64_t ans = 1;
        for (int i = 1; i <= m; i++)
        {
            ans = ans * (((n - m + i) % mod) * Pow(i, mod - 2, mod) % mod) % mod;
        }
        return ans;
    }
    int64_t Lucas(int64_t n, int64_t m)
    {
        if (m == 0)
            return 1;
        return (Lucas(n / mod, m / mod) * C(n % mod, m % mod)) % mod;
    }

    void dfs(const int64_t &n, const int64_t &maxValue, const int64_t &mod, vector<int64_t> &v,
             unordered_map<int64_t, int64_t> &count)
    {
        count[v.size()]++;

        // for (const int64_t &i : v)
        //     cout << i << ' ';
        // cout << C(n - 1, size - 1, mod) << endl;

        // ans = (ans + Lucas(n - 1, size - 1)) % mod;

        if (v.size() < n)
        {
            for (int64_t i = 2; i * v.back() <= maxValue; i++)
            {
                v.push_back(i * v.back());
                dfs(n, maxValue, mod, v, count);
                v.pop_back();
            };
        };
    };

    int idealArrays(int64_t n, int64_t maxValue)
    {
        int64_t ans = 0;
        vector<int64_t> v;
        unordered_map<int64_t, int64_t> count;

        for (int64_t i = 1; i <= maxValue; i++)
        {
            v.push_back(i);
            dfs(n, maxValue, mod, v, count);
            v.pop_back();
        };

        for (auto iter : count)
            ans = (ans + (iter.second % mod) * (Lucas(n - 1, iter.first - 1) % mod)) % mod;

        return ans;
    }
};