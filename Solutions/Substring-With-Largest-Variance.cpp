class Solution
{
  public:
    int largestVariance(string s)
    {
        int ans = 0;
        for (char M = 'a'; M <= 'z'; M++)
        {
            for (char m = 'a'; m <= 'z'; m++)
            {
                if (m != M)
                {
                    int tmp = 0, flagM = false, flagm = false;
                    for (int i = 0; i < s.length(); i++)
                    {
                        if (s[i] == M)
                        {
                            flagM = true;
                            tmp++;
                        }
                        else if (s[i] == m)
                        {
                            flagm = true;
                            if (tmp == 0)
                                flagM = flagm = false;
                            else
                                tmp--;
                        };
                        if (flagM && flagm)
                            ans = max(ans, tmp);
                    };

                    tmp = 0, flagM = false, flagm = false;
                    for (int i = s.length() - 1; i >= 0; i--)
                    {
                        if (s[i] == M)
                        {
                            flagM = true;
                            tmp++;
                        }
                        else if (s[i] == m)
                        {
                            flagm = true;
                            if (tmp == 0)
                                flagM = flagm = false;
                            else
                                tmp--;
                        };
                        if (flagM && flagm)
                            ans = max(ans, tmp);
                    };
                };
            };
        };
        return ans;
    }
};