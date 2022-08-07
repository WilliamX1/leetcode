class Solution
{
  public:
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        unordered_map<char, int> index;
        vector<int> dp(n, 1);
        index[s[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            char ch = s[i];
            for (int j = 0; j <= k && ch - j >= 'a'; j++)
                if (index.count(ch - j))
                    dp[i] = max(dp[i], dp[index[ch - j]] + 1);
            for (int j = 0; j <= k && ch + j <= 'z'; j++)
                if (index.count(ch + j))
                    dp[i] = max(dp[i], dp[index[ch + j]] + 1);

            index[ch] = i;

            // cout << i << ' ' << dp[i] << endl;
        };
        return *max_element(dp.begin(), dp.end());
    }
};