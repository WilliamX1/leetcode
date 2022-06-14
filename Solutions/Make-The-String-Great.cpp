class Solution
{
  public:
    string makeGood(string s)
    {
        bool flag;
        do
        {
            flag = false;
            int n = s.size();
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] - 'a' == s[i + 1] - 'A' || s[i] - 'A' == s[i + 1] - 'a')
                {
                    auto iter = s.erase(s.begin() + i);
                    s.erase(iter);
                    flag = true;
                    break;
                };
            };
        } while (flag);
        return s;
    }
};