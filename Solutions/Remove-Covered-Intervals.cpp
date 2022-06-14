class Solution
{
  public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<bool> del(n, false);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j && intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1])
                {
                    del[i] = true;
                    break;
                };
            };
        };
        return n - accumulate(del.begin(), del.end(), 0);
    }
};