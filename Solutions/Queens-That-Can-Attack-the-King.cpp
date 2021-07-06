#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<bool>> board;
    bool checkRow(int row_start, int row_end, int col) {
        if (row_start > row_end) swap(row_start, row_end);
        for (int i = row_start + 1; i < row_end; i++) 
            if (board[i][col]) return false;
        return true;
    };
    bool checkCol(int col_start, int col_end, int row) {
        if (col_start > col_end) swap(col_start, col_end);
        for (int i = col_start + 1; i < col_end; i++)
            if (board[row][i]) return false;
        return true;
    };
    bool checkOppo(int row_start, int col_start, int row_end, int col_end) {
        if (abs(row_start - row_end) != abs(col_start - col_end)) return false;

        int xx = row_end > row_start ? 1 : -1;
        int yy = col_end > col_start ? 1 : -1;
        int idx_x = row_start + xx, idx_y = col_start + yy;
        while (idx_x != row_end && idx_y != col_end) {
            if (board[idx_x][idx_y]) return false;
            else {
                idx_x += xx;
                idx_y += yy;
            };
        };
        return true;
    };
    bool check(int row_start, int col_start, int row_end, int col_end) {
        return (col_start == col_end && checkRow(row_start, row_end, col_start))
        || (row_start == row_end && checkCol(col_start, col_end, row_start))
        || checkOppo(row_start, col_start, row_end, col_end);
    };
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        board = vector<vector<bool>>(8, vector<bool>(8, 0));
        
        for (auto queen : queens) {
            board[queen[0]][queen[1]] = true;
        };  board[king[0]][king[1]] = true;

        vector<vector<int>> ans;
        for (auto queen : queens) {
            if (check(queen[0], queen[1], king[0], king[1])) {
                ans.push_back(queen);
            };
        };
        return ans;
    };
};