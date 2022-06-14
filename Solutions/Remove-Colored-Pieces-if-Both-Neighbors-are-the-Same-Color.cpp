class Solution
{
  public:
    bool winnerOfGame(string colors)
    {
        int cntA = 0, cntB = 0, ans = 0;
        for (const char &ch : colors)
        {
            if (ch == 'A')
            {
                cntA++;
                ans -= max(0, cntB - 2);
                cntB = 0;
            }
            else if (ch == 'B')
            {
                cntB++;
                ans += max(0, cntA - 2);
                cntA = 0;
            };
        };
        ans -= max(0, cntB - 2);
        ans += max(0, cntA - 2);

        return ans > 0;
    }
};