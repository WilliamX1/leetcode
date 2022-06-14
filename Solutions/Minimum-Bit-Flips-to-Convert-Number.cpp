class Solution
{
  public:
    int minBitFlips(int start, int goal)
    {
        int ans = start ^ goal, tot = 0;
        while (ans > 0)
        {
            tot += ans & 1;
            ans >>= 1;
        };
        return tot;
    };
};