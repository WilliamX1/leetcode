class Solution
{
  public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        unordered_map<int, int> dis1, dis2;
        int next = node1, tt = 0;
        while (next >= 0 && !dis1.count(next))
        {
            dis1[next] = tt;
            tt++;
            next = edges[next];
        };

        next = node2, tt = 0;
        while (next >= 0 && !dis2.count(next))
        {
            dis2[next] = tt;
            tt++;
            next = edges[next];
        };

        int ans = 0x7fffffff, idx = -1;
        for (int i = 0; i < n; i++)
            if (dis1.count(i) && dis2.count(i) && max(dis1[i], dis2[i]) < ans)
            {
                ans = max(dis1[i], dis2[i]);
                idx = i;
            };
        return idx;
    }
};