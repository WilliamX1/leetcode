class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int64_t n = tiles.size();
        vector<int64_t> sum(n);
        sum[0] = (int64_t) tiles[0][1] - (int64_t) tiles[0][0] + 1;
        for (int64_t i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + (int64_t) tiles[i][1] - (int64_t) tiles[i][0] + 1;
        
        vector<int64_t> leftpos(n);
        for (int64_t i = 0; i < n; ++i) leftpos[i] = (int64_t) tiles[i][0];
        int64_t ans = 0;
        for (int64_t i = 0; i < n; i++) {
            int64_t left = (int64_t) tiles[i][0], right = left + (int64_t) carpetLen - 1;
            int64_t rightidx = upper_bound(leftpos.begin(), leftpos.end(), right) - leftpos.begin();
            ans = max(ans, sum[rightidx - 1] - (int64_t) (i == 0 ? 0 : sum[i - 1]) - max((int64_t) 0, (int64_t) tiles[rightidx - 1][1] - right));
        };
        return ans;
    }
};