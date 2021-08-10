class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int m = board.size(), n = board[0].size(), point = 0;
        char ch1 = color, ch2 = color == 'B' ? 'W' : 'B';

        point = rMove - 1;
        while (point >= 0 && board[point][cMove] == ch2) point--;
        if (point < rMove - 1 && point >= 0 && board[point][cMove] == ch1) return true;

        point = rMove + 1;
        while (point < m && board[point][cMove] == ch2) point++;
        if (point > rMove + 1 && point < m && board[point][cMove] == ch1) return true;

        point = cMove - 1;
        while (point >= 0 && board[rMove][point] == ch2) point--;
        if (point < cMove - 1 && point >= 0 && board[rMove][point] == ch1) return true;

        point = cMove + 1;
        while (point < n && board[rMove][point] == ch2) point++;
        if (point > cMove + 1 && point < n && board[rMove][point] == ch1) return true;

        point = 1;
        while (rMove + point < m && cMove + point < n && board[rMove + point][cMove + point] == ch2) point++;
        if (point > 1 && rMove + point < m && cMove + point < n && board[rMove + point][cMove + point] == ch1) return true;

        point = 1;
        while (rMove + point < m && cMove - point >= 0 && board[rMove + point][cMove - point] == ch2) point++;
        if (point > 1 && rMove + point < m && cMove - point >= 0 && board[rMove + point][cMove - point] == ch1) return true;
        
        point = 1;
        while (rMove - point >= 0 && cMove + point < n && board[rMove - point][cMove + point] == ch2) point++;
        if (point > 1 && rMove - point >= 0 && cMove + point < n && board[rMove - point][cMove + point] == ch1) return true;

        point = 1;
        while (rMove - point >= 0 && cMove - point >= 0 && board[rMove - point][cMove - point] == ch2) point++;
        if (point > 1 && rMove - point >= 0 && cMove - point >= 0 && board[rMove - point][cMove - point] == ch1) return true;

        return false;
    }
};