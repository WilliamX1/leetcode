class Solution
{
  public:
    int longestPalindrome(string word1, string word2)
    {
        int len1 = word1.size(), len2 = word2.size(), len = len1 + len2;
        string word = word1 + word2;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int ans = 0;

        for (int step = 0; step < len; step++)
            for (int start = 0; start < len; start++)
            {
                int end = start + step;
                if (start == end)
                    dp[start][end] = 1;
                else if (end >= len)
                    break;
                else
                {
                    if (word[start] == word[end])
                    {
                        dp[start][end] = max(dp[start][end], dp[start + 1][end - 1] + 2);
                        if (start < len1 && end >= len1)
                            ans = max(ans, dp[start][end]);
                    }
                    else
                    {
                        dp[start][end] = max(dp[start][end], max(dp[start + 1][end], dp[start][end - 1]));
                    };
                };
            };
        return ans;
    }
};