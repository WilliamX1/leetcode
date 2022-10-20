class Solution
{
  public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = 0;
        for (int i = 1; i <= 12; i++)
        {
            for (int j = 1; j <= months[i]; j++)
            {
                string tmp = (i < 10 ? "0" : "") + to_string(i) + "-" + (j < 10 ? "0" : "") + to_string(j);
                if (arriveAlice <= tmp && tmp <= leaveAlice && arriveBob <= tmp && tmp <= leaveBob)
                    ans++;
            };
        };
        return ans;
    }
};