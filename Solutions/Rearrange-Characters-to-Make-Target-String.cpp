class Solution
{
  public:
    int rearrangeCharacters(string s, string target)
    {
        unordered_map<char, int> counts;
        for (const char &ch : target)
            counts[ch]++;

        int ans = 0x7fffffff;
        for (const auto iter : counts)
        {
            char ch = iter.first;
            int tot = 0;
            for (const char &c : s)
                if (ch == c)
                    tot++;
            ans = min(ans, tot / iter.second);
        };
        return ans;
    }
};