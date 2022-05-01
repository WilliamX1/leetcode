#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    struct node {
        int x;
        int y;
        int time;
        int ce; // 差值最小
        node () {};
        node(int x, int y, int time = 0, int ce = 0) : x(x), y(y), time(time), ce(ce) {};
    };
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<node> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    que.push(node(i, j, 0));
                };
            };
        };
        int FLAG = (m + n + 1);
        vector<vector<int>> firetimes(m, vector<int>(n, FLAG));
        while (!que.empty()) {
            node top = que.front();
            que.pop();
            
            int x = top.x, y = top.y, time = top.time;
            if (time < firetimes[x][y]) {
                firetimes[x][y] = time;
                if (x > 0 && grid[x - 1][y] == 0) que.push(node(x - 1, y, time + 1));
                if (x < m - 1 && grid[x + 1][y] == 0) que.push(node(x + 1, y, time + 1));
                if (y > 0 && grid[x][y - 1] == 0) que.push(node(x, y - 1, time + 1));
                if (y < n - 1 && grid[x][y + 1] == 0) que.push(node(x, y + 1, time + 1));
            };
        };

        // 探索是否有绝对安全路径

        que.push(node(0, 0));
        while (!que.empty()) {
            node top = que.front();
            que.pop();

            int x = top.x, y = top.y;
            if (firetimes[x][y] != FLAG) continue;
            else if (x == m - 1 && y == n - 1) return 1e9;
            else {
                if (x > 0 && grid[x - 1][y] == 0) que.push(node(x - 1, y));
                if (x < m - 1 && grid[x + 1][y] == 0) que.push(node(x + 1, y));
                if (y > 0 && grid[x][y - 1] == 0) que.push(node(x, y - 1));
                if (y < n - 1 && grid[x][y + 1] == 0) que.push(node(x, y + 1));
            };
        };

        int ans = -1;
        que.push(node(0, 0, 0, FLAG));
        while (!que.empty()) {
            node top = que.front();
            que.pop();

            int x = top.x, y = top.y, time = top.time, ce = top.ce;
            // if (firetimes[x][y] != FLAG) 
                ce = min(ce, firetimes[x][y] - time - 1);
            if (x == m - 1 && y == n - 1) {
                if (ce >= -1) ans = max(ans, max(0, ce));
            } else if (ce <= 0) continue;
            else {
                if (x > 0 && grid[x - 1][y] == 0) que.push(node(x - 1, y, time + 1, ce));
                if (x < m - 1 && grid[x + 1][y] == 0) que.push(node(x + 1, y, time + 1, ce));
                if (y > 0 && grid[x][y - 1] == 0) que.push(node(x, y - 1, time + 1, ce));
                if (y < n - 1 && grid[x][y + 1] == 0) que.push(node(x, y + 1, time + 1, ce));
            };
        };
        
        return ans;
    }
};