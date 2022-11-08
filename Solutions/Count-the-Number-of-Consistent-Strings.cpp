class Solution
{
  public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        set<char> s;
        for (const char &ch : allowed)
            s.insert(ch);

        int ans = 0;
        for (const string &str : words)
        {
            bool flag = true;
            for (const char &ch : str)
                if (!s.count(ch))
                    flag = false;
            ans += flag;
        };
        return ans;
    }
};