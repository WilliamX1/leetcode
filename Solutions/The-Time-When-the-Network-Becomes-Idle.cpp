class Solution
{
  public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
    {
        int n = patience.size();
        vector<vector<int>> edgelist(n); //
        for (vector<int> &edge : edges)
        {
            edgelist[edge[0]].push_back(edge[1]);
            edgelist[edge[1]].push_back(edge[0]);
        };

        vector<int> dis(n, INT_MAX);

        queue<vector<int>> que;
        que.push({0, 0});
        dis[0] = 0;

        while (!que.empty())
        {
            vector<int> front = que.front();
            que.pop();

            int idx = front[0], weight = front[1];
            for (int &e : edgelist[idx])
            {
                if (weight + 1 < dis[e])
                {
                    dis[e] = weight + 1;
                    que.push({e, dis[e]});
                };
            };
        };

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            // cout << dis[i] << " ";
            ans = max(ans, (2 * dis[i] - 1) / patience[i] * patience[i] + 2 * dis[i] + 1);
        };
        return ans;
    }
};