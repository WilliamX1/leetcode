class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> dp(numCarpets + 1, vector<int>(n, 0x7fffffff));
        dp[0][0] = floor[0] == '1';
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + (floor[j] == '1');
        for (int i = 1; i <= numCarpets; i++)
            for (int j = 0; j < n; j++) {
                if (j < carpetLen) dp[i][j] = 0;
                else dp[i][j] = min(dp[i][j - 1] + (floor[j] == '1'), dp[i - 1][j - carpetLen]);
            };
        return dp[numCarpets][n - 1];
    }
};