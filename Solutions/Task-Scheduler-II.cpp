class Solution
{
  public:
    long long taskSchedulerII(vector<int> &tasks, int space)
    {
        unordered_map<int, long long> last;
        long long time = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (!last.count(tasks[i]) || time - last[tasks[i]] > (long long)space)
            {
                time++;
                last[tasks[i]] = time;
            }
            else
            {
                time = last[tasks[i]] + (long long)(space + 1L);
                last[tasks[i]] = time;
            };
            // cout << time << ' ';
        }
        return time;
    }
};