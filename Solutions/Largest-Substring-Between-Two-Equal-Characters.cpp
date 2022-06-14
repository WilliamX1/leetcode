class Solution
{
  public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        unordered_map<char, int> leftmap, rightmap;
        for (int i = 0; i < s.size(); i++)
            if (!leftmap.count(s[i]))
                leftmap[s[i]] = i;
        for (int i = s.size() - 1; i >= 0; i--)
            if (!rightmap.count(s[i]))
                rightmap[s[i]] = i;
        int m = -1;
        for (char i = 'a'; i <= 'z'; i++)
        {
            m = max(m, rightmap[i] - leftmap[i] - 1);
        };
        return m;
    }
};