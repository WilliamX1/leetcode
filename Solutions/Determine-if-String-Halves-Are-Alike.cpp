class Solution
{
  public:
    bool halvesAreAlike(string s)
    {
        int n = s.size(), tot = 0;
        set<int> se = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < n; i++)
            if (se.count(s[i]))
                tot += i < n / 2 ? 1 : -1;
        return tot == 0;
    }
};