class Solution
{
  public:
    string sortString(string s)
    {
        string ans;
        char cur = 'a';
        while (!s.empty())
        {
            while (cur <= 'z')
            {
                for (auto iter = s.begin(); iter != s.end(); ++iter)
                {
                    if (*iter == cur)
                    {
                        s.erase(iter);
                        ans.push_back(cur);
                        break;
                    };
                };
                cur++;
            };
            while (cur >= 'a')
            {
                for (auto iter = s.begin(); iter != s.end(); ++iter)
                {
                    if (*iter == cur)
                    {
                        s.erase(iter);
                        ans.push_back(cur);
                        break;
                    };
                };
                cur--;
            };
        }
        return ans;
    }
};