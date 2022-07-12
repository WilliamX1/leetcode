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

    string kthSmallestPath(vector<int> &destination, int k)
    {
        string ans;
        int row = destination[0], column = destination[1];
        // cout << "row: " << row << " column: " << column << " k: " << k << endl;
        if (!row && !column)
            return "";
        else if (!row)
            return string(column, 'H');
        else if (!column)
            return string(row, 'V');
        else
        {
            int m = Lucas(row + column - 1, column - 1);
            // cout << "m: " << m << endl;
            if (k <= m)
            {
                destination[1]--;
                ans = "H" + kthSmallestPath(destination, k);
            }
            else
            {
                destination[0]--;
                ans = "V" + kthSmallestPath(destination, k - m);
            };
        };
        return ans;
    }
};