class Solution
{
  public:
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        unordered_map<int, int> times;
        int last = 0;
        for (auto &log : logs)
        {
            times[log[0]] = max(times[log[0]], log[1] - last);
            last = log[1];
        };
        int id = -1, M = 0;
        for (auto &iter : times)
        {
            if (iter.second > M || iter.second == M && iter.first < id)
            {
                id = iter.first;
                M = iter.second;
            };
        };
        return id;
    }
};