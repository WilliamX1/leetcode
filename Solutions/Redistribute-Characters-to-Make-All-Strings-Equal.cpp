class Solution
{
  public:
    bool makeEqual(vector<string> &words)
    {
        vector<int> dp(26, 0);

        for (auto str : words)
        {
            for (auto ch : str)
            {
                dp[ch - 'a']++;
            };
        };
        for (auto x : dp)
        {
            if (x % words.size() != 0)
                return false;
        }
        return true;
    }
};