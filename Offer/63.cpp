class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int _min = prices.front(), len = prices.size(), ans = 0;
        for (int i = 1; i < len; i++)
        {
            ans = max(ans, prices[i] - _min);
            _min = min(_min, prices[i]);
        };
        return ans;
    }
};