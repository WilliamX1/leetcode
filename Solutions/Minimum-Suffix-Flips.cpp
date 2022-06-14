class Solution
{
  public:
    int minFlips(string target)
    {
        int ans = 0, cnt = 0;
        for (int i = 0; i < target.length(); i++)
        {
            if (target[i] == '0' && cnt || target[i] == '1' && !cnt)
            {
                ans++;
                cnt = !cnt;
            };
        };
        return ans;
    }
};