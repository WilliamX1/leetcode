class Solution {
public:
    int getCost(vector<int> M, int n, int startAt, int moveCost, int pushCost) {
        int s = 0, ans = 0;
        while (s < n && M[s] == 0) s++;
        while (s < n) {
            if (startAt != M[s]) {
                ans += moveCost;
                startAt = M[s];
            };
            ans += pushCost;
            s++;
        };
        return ans;
    };
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int M = targetSeconds / 60, m = targetSeconds % 60;
        vector<int> v;
        v.push_back(M / 10);
        v.push_back(M % 10);
        v.push_back(m / 10);
        v.push_back(m % 10);
        int ans = 0x7fffffff;
        if (M < 100) ans = getCost(v, v.size(), startAt, moveCost, pushCost);
        if (m <= 36) {
            M--;
            m += 60;
            v.clear();
            v.push_back(M / 10);
            v.push_back(M % 10);
            v.push_back(m / 10);
            v.push_back(m % 10);
            ans = min(ans, getCost(v, v.size(), startAt, moveCost, pushCost));
        };
        return ans;
    }
};