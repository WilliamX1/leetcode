#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> dp(26, 0), ans;
        for (auto ch : p)
            dp[ch - 'a']++;

        int s_len = s.size(), p_len = p.size();
        if (s_len >= p_len)
        {
            int i;
            for (i = 0; i < p_len; i++)
                dp[s[i] - 'a']--;
            do
            {
                bool flag = true;
                for (int j = 0; j < 26; j++)
                    if (dp[j] != 0)
                    {
                        flag = false;
                        break;
                    };
                if (flag)
                    ans.push_back(i - p_len);
                if (i < s_len)
                {
                    dp[s[i] - 'a']--;
                    dp[s[i - p_len] - 'a']++;
                    i++;
                }
                else
                    break;
            } while (true);
        }
        return ans;
    }
};
int main()
{
    Solution S;
    S.findAnagrams("baa", "aa");
    return 0;
}