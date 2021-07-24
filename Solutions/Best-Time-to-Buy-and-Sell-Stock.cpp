class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, prev_min = 0x7fffffff;
        for (auto price : prices)
        {
            ans = max(ans, price - prev_min);
            prev_min = min(prev_min, price);
        };
        return ans;
    }
};