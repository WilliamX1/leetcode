class Solution
{
  public:
    vector<int> explorationSupply(vector<int> &station, vector<int> &pos)
    {
        vector<int> ans(pos.size());
        for (int i = 0; i < pos.size(); i++)
        {
            if (pos[i] < station.front())
                ans[i] = 0;
            else if (pos[i] > station.back())
                ans[i] = station.size() - 1;
            else
            {
                int iter_idx = lower_bound(station.begin(), station.end(), pos[i]) - station.begin();
                if (iter_idx > 0 && pos[i] - station[iter_idx - 1] <= station[iter_idx] - pos[i])
                    ans[i] = iter_idx - 1;
                else
                    ans[i] = iter_idx;
            };
        };
        return ans;
    }
};