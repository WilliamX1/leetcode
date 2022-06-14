class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, prev = 0;
        stack<int> up;
        for (auto price : prices)
        {
            if (up.empty())
            {
                up.push(price);
                prev = price;
                continue;
            }
            else if (price >= up.top())
            {
                up.push(price);
                continue;
            }
            else if (up.size() > 1)
                ans += up.top() - prev;

            while (up.size())
                up.pop();
            prev = price;
            up.push(price);
        };

        if (up.size() > 1)
            ans += up.top() - prev;
        return ans;
    }
};