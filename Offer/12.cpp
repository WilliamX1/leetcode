class Solution {
private:
    bool exist(vector<vector<char>>& board, string word, int idx, int x, int y, int m, int n, vector<vector<bool>>& flags) {
        if (idx == word.size()) return true;
        if (x < 0 || x >= m || y < 0 || y >= n || flags[x][y] || word[idx] != board[x][y]) return false;
        
        flags[x][y] = true;
        bool ans = (exist(board, word, idx + 1, x - 1, y, m, n, flags) || exist(board, word, idx + 1, x + 1, y, m, n, flags)
        || exist(board, word, idx + 1, x, y - 1, m, n, flags) || exist(board, word, idx + 1, x, y + 1, m, n, flags));
        flags[x][y] = false;
        return ans;
    };
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> flags(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (exist(board, word, 0, i, j, m, n, flags))
                    return true;
        return false;
    }
};