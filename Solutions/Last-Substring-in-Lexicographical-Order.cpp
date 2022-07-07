class Solution
{
  public:
    string lastSubstring(string s)
    {
        int n = s.size(), pos = n - 1, ch = s[pos];
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] >= ch)
            {
                pos = i;
                ch = s[i];
            };

        int r = pos + 1;
        while (r < n)
        {
            if (s[r] != ch)
                r++;
            else
            {
                int k = 1;
                while (pos + k < r && r + k < n && s[pos + k] == s[r + k])
                    k++;
                if (pos + k < r && r + k < n && s[pos + k] < s[r + k])
                    pos = r;
                r += k;
            };
        };
        return s.substr(pos);
    }
};