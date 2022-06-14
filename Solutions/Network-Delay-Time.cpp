#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    const int HUGE_NUM = 1e8;
    struct node
    {
        int dist;
        int target;
        node(int d, int t) : dist(d), target(t){};
        bool operator<(const node &a) const
        {
            return dist > a.dist;
        };
        node *next;
    };
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int64_t> v(n + 1, HUGE_NUM);

        priority_queue<node, vector<node>> p;
        p.push(node(0, k));

        while (!p.empty())
        {
            node cur = p.top();
            p.pop();

            if (v[cur.target] != HUGE_NUM)
                continue; // 忽略已找到最小值的点

            v[cur.target] = cur.dist;

            for (auto time : times)
            {
                if (time[0] == cur.target)
                {
                    p.push(node(min(time[2] + v[cur.target], int64_t(v[time[1]])), time[1]));
                };
            };
        };

        v[k] = 0;
        int64_t ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == HUGE_NUM)
                return -1;
            else
                ans = max(ans, v[i]);
        };

        return ans;
    }
};