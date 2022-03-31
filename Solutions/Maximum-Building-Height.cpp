class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.insert(restrictions.begin(), {1, 0});
        restrictions.insert(restrictions.end(), {n, n - 1});

        sort(restrictions.begin(), restrictions.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        for (int i = 0; i < (int) restrictions.size() - 1; i++) {
            restrictions[i + 1][1] = min(restrictions[i + 1][1], restrictions[i][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        };

        for (int i = (int) restrictions.size() - 2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        };

        int ans = 0;
        for (int i = 0; i < (int) restrictions.size() - 1; i++) {
            ans = max(ans, (restrictions[i + 1][1] + restrictions[i][1] + restrictions[i + 1][0] - restrictions[i][0]) >> 1);
        };
        return ans;
    }
};