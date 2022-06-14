class Solution
{
  public:
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit)
    {
        int times = 0;
        for (const vector<int> &fruit : fruits)
        {
            int type = fruit[0], num = fruit[1];
            times += time[type] * ((num - 1) / limit + 1);
        };
        return times;
    }
};