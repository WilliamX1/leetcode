class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> start(n, 0), end(n, 0);

        int m = prices[0];
        for (int i = 1; i < n; i++)
        {
            end[i] = prices[i] - m;
            m = min(m, prices[i]);
        };

        int M = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            start[i] = M - prices[i];
            M = max(M, prices[i]);
        };

        for (int i = 1; i < n; i++)
            end[i] = max(end[i], end[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            start[i] = max(start[i], start[i + 1]);

        int ans = max(0, end[n - 1]);
        for (int i = 1; i < n - 1; i++)
            ans = max(ans, end[i] + start[i + 1]);
        return ans;
    }
};