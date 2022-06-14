class Solution
{
  public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> win, loss;
        for (const vector<int> &m : matches)
        {
            win[m[0]]++;
            loss[m[1]]++;
        };
        vector<vector<int>> ans(2, vector<int>());
        for (const auto iter : win)
        {
            if (!loss[iter.first])
                ans[0].push_back(iter.first);
        };
        for (const auto iter : loss)
        {
            if (iter.second == 1)
                ans[1].push_back(iter.first);
        };
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};