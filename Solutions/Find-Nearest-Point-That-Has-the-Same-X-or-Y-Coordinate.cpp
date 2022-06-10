class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1, dis = 0x7fffffff;
        for (int i = 0; i < points.size(); i++) {
            const vector<int>& p = points[i];
            if (p[0] == x || p[1] == y) {
                int d = abs(p[0] - x) + abs(p[1] - y);
                if (d < dis) {
                    dis = d;
                    ans = i;
                };
            };
        };
        return ans;
    }
};