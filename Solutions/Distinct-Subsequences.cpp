class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) dp[i][j] = t[i] == s[j];
                else if (i == 0) dp[i][j] = (t[i] == s[j]) + dp[i][j - 1];
                else if (j == 0) dp[i][j] = 0;
                else dp[i][j] = (t[i] == s[j] ? dp[i - 1][j - 1] : 0) + dp[i][j - 1];
            };
        return dp[n - 1][m - 1];
    }
};