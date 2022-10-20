class Solution
{
  public:
    int StoredEnergy(int storeLimit, const vector<int> &power, const vector<vector<int>> &supply)
    {
        int supply_idx = 0, ans = 0;
        for (int i = 0; i < power.size(); i++)
        {
            if (i < supply[supply_idx][0])
            {
                ans += power[i];
                ans = min(ans, storeLimit);
            }
            else
            {
                if (supply_idx < supply.size() - 1 && i >= supply[supply_idx + 1][0])
                    supply_idx++;
                if (power[i] < supply[supply_idx][1])
                {
                    ans -= supply[supply_idx][1] - power[i];
                    ans = max(ans, 0);
                }
                else if (power[i] > supply[supply_idx][2])
                {
                    ans += power[i] - supply[supply_idx][2];
                    ans = min(ans, storeLimit);
                }
                else
                {
                };
            };
        };
        return ans;
    }
};