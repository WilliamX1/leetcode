class Solution
{
  public:
    int numWays(int n)
    {
        int f0 = 0, f1 = 0, f2 = 1, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            f0 = f1;
            f1 = f2;
            f2 = (f0 + f1) % mod;
        };
        return f2;
    }
};