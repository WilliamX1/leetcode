class Solution
{
  public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> umap;
        char ch = 'a';
        for (const char &k : key)
            if ('a' <= k && k <= 'z' && !umap.count(k))
                umap[k] = ch++;
        for (char &ch : message)
            if ('a' <= ch && ch <= 'z' && umap.count(ch))
                ch = umap[ch];
        return message;
    }
};