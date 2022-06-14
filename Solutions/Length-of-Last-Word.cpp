class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        int idx = s.size() - 1, tot = 0;
        while (idx >= 0 && s[idx] == ' ')
            idx--;
        while (idx >= 0 && s[idx] != ' ')
        {
            idx--;
            tot++;
        };
        return tot;
    }
};