class Solution {
public:
    vector<int> ans;
    int cnt = 0;
    void dfs(const int& numArrows, const vector<int>& aliceArrows, const int idx, const int n, vector<int> bobArrows, int tot) {
        if (idx == n) {
            if (tot > cnt) {
                if (numArrows > 0) bobArrows[0] += numArrows;
                
                ans = bobArrows;
                cnt = tot;
            };
            return;
        };

        dfs(numArrows, aliceArrows, idx + 1, n, bobArrows, tot);

        if (numArrows > aliceArrows[idx]) {
            bobArrows[idx] = aliceArrows[idx] + 1;
            dfs(numArrows - bobArrows[idx], aliceArrows, idx + 1, n, bobArrows, tot + idx);
        };
        return;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> bobArrows(n, 0);
        dfs(numArrows, aliceArrows, 0, n, bobArrows, 0);
        return ans;
    }
};