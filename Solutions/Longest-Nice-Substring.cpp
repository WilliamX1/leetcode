class Solution
{
  public:
    string longestNiceSubstring(string s)
    {
        int n = s.length(), ans = 0;
        int start, end;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                if (j - i + 1 <= ans)
                    continue;

                unordered_map<char, int> flags;
                bool flag = true;
                for (int k = i; k <= j; k++)
                    flags[s[k]] = 1;
                for (char ch = 'a'; ch <= 'z'; ch++)
                    if (flags[ch] ^ flags[ch - 'a' + 'A'])
                    {
                        flag = false;
                        break;
                    };
                if (flag)
                {
                    ans = j - i + 1;
                    start = i;
                    end = j;
                };
            };
        return ans ? s.substr(start, end - start + 1) : "";
    }
};