class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> gd(m, vector<bool>(n, false)), wa(m, vector<bool>(n, false));
        for (const vector<int>& g : guards) {
            gd[g[0]][g[1]] = true;
        };
        for (const vector<int>& w : walls) {
            wa[w[0]][w[1]] = true;
        }

        vector<vector<bool>> see(m, vector<bool>(n, false));
        vector<vector<bool>> answer(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {                
                if (gd[i][j]) see[i][j] = true;
                else if (wa[i][j] || j == 0) see[i][j] = false;
                else see[i][j] = see[i][j - 1];

                if (see[i][j] && !wa[i][j] && !gd[i][j])
                    answer[i][j] = true;
            };
        };
        see = vector<vector<bool> >(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (gd[i][j]) see[i][j] = true;
                else if (wa[i][j] || j == n - 1) see[i][j] = false;
                else see[i][j] = see[i][j + 1];

                if (see[i][j] && !wa[i][j] && !gd[i][j])
                    answer[i][j] = true;
            };
        };
        see = vector<vector<bool> >(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (gd[i][j]) see[i][j] = true;
                else if (wa[i][j] || i == 0) see[i][j] = false;
                else see[i][j] = see[i - 1][j];

                if (see[i][j] && !wa[i][j] && !gd[i][j])
                    answer[i][j] = true;
            };
        };
        see = vector<vector<bool> >(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i >= 0; i--) {
                if (gd[i][j]) see[i][j] = true;
                else if (wa[i][j] || i == m - 1) see[i][j] = false;
                else see[i][j] = see[i + 1][j];

                if (see[i][j] && !wa[i][j] && !gd[i][j])
                    answer[i][j] = true;
            };
        };

        int tt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tt += answer[i][j];
            }
        }
        
        return m * n - tt - guards.size() - walls.size();
    }
};