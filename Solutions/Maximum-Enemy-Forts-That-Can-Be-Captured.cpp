class Solution
{
  public:
    int captureForts(vector<int> &forts)
    {
        int ans = 0;

        int idx = 0;

        while (idx < forts.size())
        {
            if (forts[idx] == 1)
            {
                int tmp = 0;
                while (++idx < forts.size() && forts[idx] == 0)
                {
                    tmp++;
                };
                if (idx < forts.size() && forts[idx] == -1)
                    ans = max(ans, tmp);
            }
            else if (forts[idx] == -1)
            {
                int tmp = 0;
                while (++idx < forts.size() && forts[idx] == 0)
                {
                    tmp++;
                };
                if (idx < forts.size() && forts[idx] == 1)
                    ans = max(ans, tmp);
            }
            else
                idx++;
        };
        return ans;

        return ans;
    }
};