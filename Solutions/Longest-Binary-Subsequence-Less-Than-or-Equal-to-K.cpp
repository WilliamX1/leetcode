class Solution
{
  public:
    int longestSubsequence(string s, int k)
    {
        int ans = 0;
        for (const char &ch : s)
            ans += ch == '0';
        int64_t base = 0, tot = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                tot += 1UL << base;
                if (tot <= k)
                    ans++;
                else
                    break;
            };
            base++;
            if (base > 31)
                break;
        };
        return ans;
    }
};