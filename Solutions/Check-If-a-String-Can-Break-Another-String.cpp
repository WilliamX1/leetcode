class Solution
{
  public:
    bool checkIfCanBreak(string s1, string s2)
    {
        int n = s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (s1[i] >= s2[i])
                continue;
            else
            {
                flag = false;
                break;
            };
        if (!flag)
        {
            flag = true;
            for (int i = 0; i < n; i++)
                if (s2[i] >= s1[i])
                    continue;
                else
                {
                    flag = false;
                    break;
                };
        };
        return flag;
    }
};