#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<vector<int>> que;
        int m = isWater.size(), n = isWater[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    isWater[i][j] = 0;
                    que.push({i, j, 0});
                } else isWater[i][j] = 0x7fffffff;
            };
        };

        while (!que.empty()) {
            vector<int> front = que.front();
            que.pop();
            
            int x = front[0], y = front[1], height = front[2];

            if (x > 0 && isWater[x - 1][y] > height + 1) {
                isWater[x - 1][y] = height + 1;
                que.push({x - 1, y, height + 1});
            };
            if (x < m - 1 && isWater[x + 1][y] > height + 1) {
                isWater[x + 1][y] = height + 1;
                que.push({x + 1, y, height + 1});
            };
            if (y > 0 && isWater[x][y - 1] > height + 1) {
                isWater[x][y - 1] = height + 1;
                que.push({x, y - 1, height + 1});
            };
            if (y < n - 1 && isWater[x][y + 1] > height + 1) {
                isWater[x][y + 1] = height + 1;
                que.push({x, y + 1, height + 1});
            };
        };
        return isWater;
    }
};