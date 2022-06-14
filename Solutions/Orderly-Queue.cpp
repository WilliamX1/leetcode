class Solution
{
  public:
    string orderlyQueue(string s, int k)
    {
        string ans = s;
        if (k == 1)
        {
            string tmp = s;
            for (const char &ch : s)
            {
                tmp.erase(tmp.begin());
                tmp.push_back(ch);
                if (tmp < ans)
                    ans = tmp;
            };
        }
        else
        {
            sort(s.begin(), s.end());
            ans = s;
        };
        return ans;
    }
};