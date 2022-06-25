class Solution
{
  public:
    int countAsterisks(string s)
    {
        int tot = 0, cnt = 0;
        bool flag = false;
        for (const char &ch : s)
        {
            if (ch == '|')
            {
                flag = !flag;
            };
            if (ch == '*')
            {
                tot++;
                if (flag)
                    cnt++;
            };
        };
        return tot - cnt;
    }
};