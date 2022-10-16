class Solution
{
  public:
    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int64_t> v;
        int64_t tmp = 1, mod = 1e9 + 7;
        while (n)
        {
            if (n & 1)
                v.push_back(tmp);

            tmp <<= 1;
            n >>= 1;
        };
        sort(v.begin(), v.end());

        vector<int> ret;
        for (const vector<int> &q : queries)
        {
            int64_t tt = 1;
            for (int i = q[0]; i <= q[1]; i++)
            {
                tt = (tt * v[i]) % mod;
            };
            ret.push_back(tt);
        };
        return ret;
    }
};