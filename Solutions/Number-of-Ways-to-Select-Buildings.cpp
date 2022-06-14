class Solution
{
  public:
    long long numberOfWays(string s)
    {
        // 101 或者 010
        int64_t n = s.size();
        vector<int64_t> one(n, 0), zero(n, 0), one_zero(n, 0), zero_one(n, 0);

        zero[0] = s[0] == '0';
        one[0] = s[0] == '1';

        for (int64_t i = 1; i < n; i++)
        {
            one[i] = one[i - 1] + (s[i] == '1');
            zero[i] = zero[i - 1] + (s[i] == '0');
        };

        for (int64_t i = 1; i < n; i++)
        {
            one_zero[i] = one_zero[i - 1] + (s[i] == '0' ? one[i - 1] : 0);
            zero_one[i] = zero_one[i - 1] + (s[i] == '1' ? zero[i - 1] : 0);
        };
        int64_t tot = 0;
        for (int64_t i = 2; i < n; i++)
        {
            tot += s[i] == '0' ? zero_one[i - 1] : one_zero[i - 1];
        };
        return tot;
    }
};