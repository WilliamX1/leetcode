class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        vector<int> fac(n);
        fac[0] = 1;
        for (int i = 1; i < n; i++)
            fac[i] = fac[i - 1] * i;

        --k;
        string ans;
        vector<int> valid(n + 1, 1);
        for (int i = n - 1; i >= 0; i--)
        {
            int order = k / fac[i] + 1;
            for (int j = 1; j <= n; j++)
            {
                order -= valid[j];
                if (!order)
                {
                    ans.push_back(j + '0');
                    valid[j] = 0;
                    break;
                };
            };
            k %= fac[i];
        }
        return ans;
    }
};