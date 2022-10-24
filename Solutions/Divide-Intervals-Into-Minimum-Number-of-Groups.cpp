class Solution
{
  public:
    int minGroups(vector<vector<int>> &intervals)
    {
        vector<int> updown(1e6 + 7, 0);
        for (const vector<int> &v : intervals)
        {
            updown[v[0]]++;
            updown[v[1] + 1]--;
        };
        for (int i = 1; i < 1e6 + 7; i++)
            updown[i] += updown[i - 1];
        return *max_element(updown.begin(), updown.end());
    }
};