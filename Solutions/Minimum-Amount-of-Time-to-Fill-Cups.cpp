class Solution
{
  public:
    int fillCups(vector<int> &amount)
    {
        int tt = 0;
        while (accumulate(amount.begin(), amount.end(), 0))
        {
            sort(amount.begin(), amount.end(), greater<int>());
            amount[0]--;
            if (amount[1])
                amount[1]--;
            tt++;
        };
        return tt;
    }
};