class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size(), n2 = t.size();

        if (n1 > n2) return false;
        
        vector<vector<int>> dp(n1, vector<int>(n2, false));
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < n2; j++) {
                if (i == 0 || j == 0) dp[i][j] = s[i] == t[j];
                else if (s[i] == t[j]) {
                    for (int k = 0; k < j; k++)
                        dp[i][j] |= dp[i - 1][k];
                };
                if (i == n1 - 1 && dp[i][j]) return true;
            };
        return !n1;
    }
};