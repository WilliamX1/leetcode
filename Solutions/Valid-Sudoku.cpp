class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    for (int k = 0; k < N; k++) {
                        if (k != i && board[k][j] == board[i][j] || k != j && board[i][k] == board[i][j]) {
                            return false;
                        };
                    };
                    int leftx = i / 3 * 3, lefty = j / 3 * 3;
                    for (int k = leftx; k <= leftx + 2; k++)
                        for (int l = lefty; l <= lefty + 2; l++) {
                            if ((k != i || l != j) && board[i][j] == board[k][l]) {
                                return false;
                            };
                        };
                };
            };
        return true;
    }
};