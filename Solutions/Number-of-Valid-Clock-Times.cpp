class Solution
{
  public:
    bool OK(string time)
    {
        return (time[0] <= '1' || time[0] == '2' && time[1] <= '3') && (time[3] <= '5');
    };
    int countTime(string time)
    {
        int ans = 0;
        for (int i1 = '0'; i1 <= '9'; i1++)
            for (int i2 = '0'; i2 <= '9'; i2++)
                for (int i3 = '0'; i3 <= '9'; i3++)
                    for (int i4 = '0'; i4 <= '9'; i4++)
                    {
                        string tmp = time;
                        if (time[0] == '?' || time[0] == i1)
                            tmp[0] = i1;
                        else
                            continue;

                        if (time[1] == '?' || time[1] == i2)
                            tmp[1] = i2;
                        else
                            continue;
                        if (time[3] == '?' || time[3] == i3)
                            tmp[3] = i3;
                        else
                            continue;
                        if (time[4] == '?' || time[4] == i4)
                            tmp[4] = i4;
                        else
                            continue;
                        ans += OK(tmp);
                    };
        return ans;
    }
};