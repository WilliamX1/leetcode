class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int n = stockPrices.size(), tot = 1;
        for (int i = 2; i < n; i++) {
            if ((int64_t)(stockPrices[i][1] - stockPrices[i - 1][1]) * (int64_t)(stockPrices[i - 1][0] - stockPrices[i - 2][0]) 
                == (int64_t)(stockPrices[i - 1][1] - stockPrices[i - 2][1]) * (int64_t)(stockPrices[i][0] - stockPrices[i - 1][0]))
                    continue;
            else tot++;
        };
        return n < 2 ? 0 : tot;
    }
};