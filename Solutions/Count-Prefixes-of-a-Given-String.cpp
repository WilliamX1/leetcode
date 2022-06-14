class Solution
{
  public:
    int countPrefixes(vector<string> &words, string s)
    {
        int tot = 0;
        for (const string &word : words)
        {
            if (s.find(word) == 0)
                tot++;
        };
        return tot;
    }
};