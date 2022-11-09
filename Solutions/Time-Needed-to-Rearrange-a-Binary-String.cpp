class Solution
{
  public:
    int secondsToRemoveOccurrences(string s)
    {
        int n = s.size(), cnt0 = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                cnt0++;
            else if (cnt0 > 0)
                ans = max(ans + 1, cnt0);
        };
        return ans;
    }
};