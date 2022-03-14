class Solution {
public:
    const int N = 9;
    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (x == N) return true;

        if (board[x][y] != '.') {
            return dfs(board, (y == N - 1 ? x + 1 : x), (y == N - 1 ? 0 : y + 1));
        } else {
            for (int i = 1; i <= N; i++) {
                bool flag = true;
                for (int j = 0; j < N; j++) 
                    if (board[x][j] - '0' == i || board[j][y] - '0' == i) {
                        flag = false;
                        break;
                    };
                
                int leftx =  x / 3 * 3, lefty = y / 3 * 3;
                for (int j = leftx; j <= leftx + 2; j++)
                    for (int k = lefty; k <= lefty + 2; k++)
                        if (board[j][k] - '0' == i) {
                            flag = false;
                            break;
                        };

                if (!flag) continue;
                
                board[x][y] = char(i + '0');

                if (dfs(board, (y == N - 1 ? x + 1 : x), (y == N - 1 ? 0 : y + 1))) return true;
                else board[x][y] = '.';
            };
            return false;
        };
    };
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};