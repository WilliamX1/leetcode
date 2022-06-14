class Solution
{
  public:
    int numberOfMatches(int n)
    {
        int ans = 0;
        while (n > 1)
        {
            if (n & 1)
            {
                ans += 1 + ((n - 1) >> 1);
                n = (n - 1) >> 1;
            }
            else
            {
                ans += n >> 1;
                n >>= 1;
            };
        };
        return ans;
    }
};