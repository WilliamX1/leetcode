class Solution
{
  public:
    char repeatedCharacter(string s)
    {
        unordered_map<char, bool> umap;
        for (const char &ch : s)
            if (umap.count(ch))
                return ch;
            else
                umap[ch] = true;
        return 0;
    }
};