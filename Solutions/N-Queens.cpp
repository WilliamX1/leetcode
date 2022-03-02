class Solution {
public:
    void DFS(vector<string> states, int n, int tot, int x, int y, vector< vector<string> >& ans) {
        if (tot == n) {
            ans.push_back(states);
            return;
        };

        for (int j = y; j < n; j++) {
            bool flag = true;
            for (int i = 0; i < n; i++)
                if (states[x][i] == 'Q' || states[i][j] == 'Q') flag = false;
            for (int i = -n; i < n; i++)
                if (0 <= x + i && x + i < n && 0 <= j + i && j + i < n && states[x + i][j + i] == 'Q'
                || 0 <= x + i && x + i < n && 0 <= j - i && j - i < n && states[x + i][j - i] == 'Q') flag = false;
            if (flag) {
                states[x][j] = 'Q';
                DFS(states, n, tot + 1, x, j + 1, ans);
                states[x][j] = '.';
            };
        };

        for (int i = x + 1; i < n; i++)
            for (int j = 0; j < n; j++) {
                bool flag = true;
                for (int k = 0; k < n; k++)
                    if (states[i][k] == 'Q' || states[k][j] == 'Q') flag = false;
                for (int k = -n; k < n; k++)
                    if (0 <= i + k && i + k < n && 0 <= j + k && j + k < n && states[i + k][j + k] == 'Q'
                    || 0 <= i + k && i + k < n && 0 <= j - k && j - k < n && states[i + k][j - k] == 'Q') flag = false;
                if (flag) {
                    states[i][j] = 'Q';
                    DFS(states, n, tot + 1, i, j + 1, ans);
                    states[i][j] = '.';
                };
            };
        return;
    };
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string> > result;
        vector< string > states(n, string(n, '.'));
        DFS(states, n, 0, 0, 0, result);
        return result;
    }
};