class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int start_x = 0, start_y = 0, m = grid.size(), n = grid[0].size();
        int x_s = m - 1, y_s = n - 1;
        while ((1 + start_x) * 2 <= m && (1 + start_y) * 2 <= n) {
            int x = start_x, y = start_y;
            int tmp_xs = x_s, tmp_ys = y_s;
            deque<int> q;
            do {
                q.push_back(grid[x][y]);
                y++, tmp_ys--;
            } while (tmp_ys);
            do {
                q.push_back(grid[x][y]);
                x++, tmp_xs--;
            } while (tmp_xs);
            tmp_xs = x_s, tmp_ys = y_s;
            do {
                q.push_back(grid[x][y]);
                y--, tmp_ys--;
            } while (tmp_ys);
            do {
                q.push_back(grid[x][y]);
                x--, tmp_xs--;
            } while (tmp_xs);

            int tmp_k = k % q.size();
            while (tmp_k > 0) {
                tmp_k--;
                int tmp = q.front();
                q.pop_front();
                q.push_back(tmp);
            };
            tmp_xs = x_s, tmp_ys = y_s;
            do {
                grid[x][y] = q.front();
                q.pop_front();
                y++, tmp_ys--;
            } while (tmp_ys);
            do {
                grid[x][y] = q.front();
                q.pop_front();
                x++, tmp_xs--;
            } while (tmp_xs);
            tmp_xs = x_s, tmp_ys = y_s;
            do {
                grid[x][y] = q.front();
                q.pop_front();
                y--, tmp_ys--;
            } while (tmp_ys);
            do {
                grid[x][y] = q.front();
                q.pop_front();
                x--, tmp_xs--;
            } while (tmp_xs);

            start_x++, start_y++;
            x_s -= 2, y_s -= 2;
        };
        return grid;
    }
};