class Solution
{
  public:
    string greatestLetter(string s)
    {
        for (char ch = 'Z'; ch >= 'A'; ch--)
        {
            bool flag1 = false, flag2 = false;
            for (const char &sch : s)
            {
                if (sch == ch)
                    flag1 = true;
                if (sch == char(ch - 'A' + 'a'))
                    flag2 = true;
            };
            if (flag1 && flag2)
            {
                // cout << "here";
                return string(1, ch);
            }
        };
        return "";
    }
};