class Solution
{
  public:
    struct cmp
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[1] > b[1];
        }
    };

    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        priority_queue<vector<int>, vector<vector<int>>, cmp> pque;

        int idx = 0, tot = 0;
        for (int d = 1; d <= 1e5; d++)
        {
            while (idx < events.size() && events[idx][0] <= d)
            {
                pque.push(events[idx]);
                idx++;
            };
            while (!pque.empty() && pque.top()[1] < d)
                pque.pop();
            if (!pque.empty())
            {
                tot++;
                pque.pop();
            };
        };
        return tot;
    }
};