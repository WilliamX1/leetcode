class Solution
{
  public:
    string strWithout3a3b(int a, int b)
    {
        string ans;
        int cnta = 0, cntb = 0;
        while (a && b)
        {
            if (a > b)
            {
                if (cnta < 2)
                {
                    ans += 'a';
                    a--;
                    cnta++;
                }
                else
                {
                    ans += 'b';
                    b--;
                    cnta = 0;
                    cntb = 1;
                };
            }
            else
            {
                if (cntb < 2)
                {
                    ans += 'b';
                    b--;
                    cntb++;
                }
                else
                {
                    ans += 'a';
                    a--;
                    cnta = 1;
                    cntb = 0;
                };
            };
        };
        ans.append(string(a, 'a'));
        ans.append(string(b, 'b'));
        return ans;
    }
};