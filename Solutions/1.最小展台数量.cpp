class Solution
{
  public:
    int minNumBooths(vector<string> &demand)
    {
        unordered_map<char, int> ans;
        for (string &d : demand)
        {
            unordered_map<char, int> tmp;
            for (char &ch : d)
                tmp[ch]++;
            for (char ch = 'a'; ch <= 'z'; ch++)
                ans[ch] = max(ans[ch], tmp[ch]);
        };
        int ret = 0;
        for (char ch = 'a'; ch <= 'z'; ch++)
            ret += ans[ch];
        return ret;
    }
};