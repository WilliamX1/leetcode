#include <iostream>
#include <vector>

using namespace std;

bool dfs(const int size, const char (*board)[100], vector< vector<bool> >& flag, const char ch, int x, int y) {
    flag[x][y] = true;

    if (x == 0 && ch == 'R' && board[x][y] == 'R' || y == 0 && ch == 'B' && board[x][y] == 'B') return true;

    if (board[x][y] != ch) return false;

    int ans = false;
    if (ch == 'R') {
        if (x < size - 1 && !flag[x + 1][y]) ans |= dfs(size, board, flag, ch, x + 1, y); if (ans) return ans; // 下
        if (y < size - 1 && !flag[x][y + 1]) ans |= dfs(size, board, flag, ch, x, y + 1); if (ans) return ans; // 右
        if (x > 0 && !flag[x - 1][y]) ans |= dfs(size, board, flag, ch, x - 1, y); if (ans) return ans; // 上
        if (y > 0 && !flag[x][y - 1]) ans |= dfs(size, board, flag, ch, x, y - 1); if (ans) return ans; // 左
    } else if (ch == 'B') {
        if (x > 0 && !flag[x - 1][y]) ans |= dfs(size, board, flag, ch, x - 1, y); if (ans) return ans; // 上
        if (y > 0 && !flag[x][y - 1]) ans |= dfs(size, board, flag, ch, x, y - 1); if (ans) return ans; // 左
        if (x < size - 1 && !flag[x + 1][y]) ans |= dfs(size, board, flag, ch, x + 1, y); if (ans) return ans; // 下
        if (y < size - 1 && !flag[x][y + 1]) ans |= dfs(size, board, flag, ch, x, y + 1); if (ans) return ans; // 右
    }
    return ans; 
};

string FindBoardStatus(int size, char (*board)[100]) {
    // TODO: Complete this function to find the status of the board.
    string ans = "";
    int cntB = 0, cntR = 0, winB = 0, winR = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 'B') cntB++;
            if (board[i][j] == 'R') cntR++;
        };

    vector< vector<bool> > flagB(size, vector<bool>(size, false));
    for (int i = 0; i < size; i++) {
        winB += dfs(size, board, flagB, 'B', i, size - 1);
    };
    vector< vector<bool> > flagR(size, vector<bool>(size, false));
    for (int j = 0; j < size; j++) {
        winR += dfs(size, board, flagR, 'R', size - 1, j);
    };

    // cout << "cntB: " << cntB << "cntR: " << cntR << "winB " << winB << "winR " << winR << endl;

    if (abs(cntB - cntR) > 1 || winB + winR > 1) ans = "Impossible";
    else if (winB > 0) ans = "Blue wins";
    else if (winR > 0) ans = "Red wins";
    else ans = "Nobody wins";
    return ans;
}

int main() {
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    int n;
    cin >> n;
    char board[100][100];
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        cin >> board[r][c];
      }
    }
    cout << "Case #" << tc << ": " << FindBoardStatus(n, board) << endl;
  }
  return 0;
}
