class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;

        int len = s.size(), last_idx = -1, ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (m.find(s[i]) != m.end())
                last_idx = max(last_idx, m[s[i]]);
            m[s[i]] = i;
            ans = max(ans, i - last_idx);
        };
        return ans;
    }
};