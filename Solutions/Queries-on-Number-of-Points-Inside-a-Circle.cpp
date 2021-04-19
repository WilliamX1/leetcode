#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    bool is_contain(int x1, int y1, int x2, int y2, int dis) {
        return pow((x1 - x2), 2) + pow((y1 - y2), 2) <= pow(dis, 2);
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < points.size(); j++) {
                cnt += is_contain(points[j][0], points[j][1], queries[i][0], queries[i][1], queries[i][2]);
            };
            res.push_back(cnt);
        };
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> points = {{1,3},{3,3},{5,3},{2,2}};
    vector<vector<int>> queries = {{2,3,1},{4,3,1},{1,1,2}};
    S.countPoints(points, queries);
    return 0;
}