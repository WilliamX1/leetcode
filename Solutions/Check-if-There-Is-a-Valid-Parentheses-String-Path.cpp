class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<set<int>>> dp(n, vector<set<int>>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    if (grid[0][0] == ')') return false;
                    else dp[0][0].insert(1);
                } else {
                    if (i > 0) {
                        if (grid[i][j] == '(')
                            for (const int& num : dp[i - 1][j])
                                dp[i][j].insert(num + 1);
                        if (grid[i][j] == ')')
                            for (const int& num : dp[i - 1][j])
                                if (num > 0)
                                    dp[i][j].insert(num - 1);
                    };
                    if (j > 0) { 
                        if (grid[i][j] == '(')
                            for (const int& num : dp[i][j - 1])
                                dp[i][j].insert(num + 1);
                        if (grid[i][j] == ')')
                            for (const int& num : dp[i][j - 1])
                                if (num > 0)
                                    dp[i][j].insert(num - 1);
                    };
                };
            };
        return dp[n - 1][m - 1].count(0);
    }
};