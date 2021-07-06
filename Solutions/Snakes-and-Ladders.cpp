class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dp(n + 1, 0x7fffffff); dp[1] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int step = 1; step <= 6; step++) {
                int x = (i - 1) / 6;
                int y = x & 1 ? i - 6 * x : 6 * (x + 1) - i;    
                if (board[x][y] == -1) dp[i + step] = min(dp[i] + 1, dp[i + step]);
                else {
                    int xx = (board[x][y] - 1) / 6;
                    int yy = xx & 1 ? board[x][y] - 6 * xx : 6 * (xx + 1) - board[x][y];
                    dp[board[x][y]] = min(dp[i] + 1, dp[board[x][y]]);
                }
            }
        }

    }
};