class Solution
{
  public:
    int countTriples(int n)
    {
        int ans = 0;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
            {
                int res = i * i + j * j;
                if (int(sqrt(res)) * int(sqrt(res)) == res && sqrt(res) <= n)
                    ans++;
            };
        return ans;
    }
};