class Solution
{
  public:
    int numPrimeArrangements(int n)
    {
        int64_t tt = 0;
        for (int64_t i = 2; i <= n; i++)
        {
            bool flag = true;
            for (int64_t j = 2; j < i; j++)
                if (i % j == 0)
                    flag = false;
            tt += flag;
        };
        cout << "tt: " << tt << endl;
        int64_t ans = 1, mod = 1e9 + 7;
        for (int64_t i = 1; i <= tt; i++)
            ans = (ans * i) % mod;
        for (int64_t i = 1; i <= n - tt; i++)
            ans = (ans * i) % mod;
        return ans;
    }
};