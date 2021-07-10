class Solution {
public:
    bool dfs(vector<vector<char>>& board, int m, int n, string word, int len, int idx, int x, int y, vector<vector<bool>>& been) {
        if (idx == len - 1 && board[x][y] == word[idx]) return true;
        if (board[x][y] != word[idx]) return false;

        been[x][y] = true;

        bool flag = false;
        if (x > 0 && !been[x - 1][y]) flag |= dfs(board, m, n, word, len, idx + 1, x - 1, y, been);
        if (x < m - 1 && !been[x + 1][y]) flag |= dfs(board, m, n, word, len, idx + 1, x + 1, y, been);
        if (y > 0 && !been[x][y - 1]) flag |= dfs(board, m, n, word, len, idx + 1, x, y - 1, been);
        if (y < n - 1 && !been[x][y + 1]) flag |= dfs(board, m, n, word, len, idx + 1, x, y + 1, been);
        
        been[x][y] = false;
        return flag;
    };
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> been(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, m, n, word, word.size(), 0, i, j, been)) return true;
        return false;
    }
};