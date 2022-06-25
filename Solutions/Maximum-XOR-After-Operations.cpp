class Solution
{
  public:
    int maximumXOR(vector<int> &nums)
    {
        vector<int> v(31, 0);
        for (const int &num : nums)
        {
            int nn = num, i = 0;
            while (nn > 0)
            {
                v[i++] += nn & 1;
                nn >>= 1;
            };
        };
        int ans = 0, tt = 1;
        for (int i = 0; i < 31; i++)
        {
            if (v[i])
                ans += tt;
            tt <<= 1;
        };
        return ans;
    }
};