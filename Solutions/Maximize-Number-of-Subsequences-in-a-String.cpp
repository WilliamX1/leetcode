class Solution
{
  public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        int64_t ch1, ch2, tot1 = 0, tot2 = 0;
        ch1 = 1, ch2 = 0;
        for (const char &ch : text)
        {
            if (ch == pattern[1])
            {
                tot1 += ch1;
                ch2++;
            };
            if (ch == pattern[0])
                ch1++;
        };

        ch1 = 0;
        ch2 = 1;
        for (int i = text.size() - 1; i >= 0; i--)
        {
            if (text[i] == pattern[0])
            {
                tot2 += ch2;
                ch1++;
            };
            if (text[i] == pattern[1])
                ch2++;
        };
        return max(tot1, tot2);
    }
};