class Solution
{
  public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        vector<int> distanceToLastNode(n + 1, 2e9);
        distanceToLastNode[n] = 0;

        vector<vector<vector<int>>> edgeList(n + 1);
        for (const vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1], weight = edge[2];
            edgeList[u].push_back({v, weight});
            edgeList[v].push_back({u, weight});
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
        pque.push(make_pair(0, n));

        vector<bool> havebeen(n + 1, false);

        while (!pque.empty())
        {
            const int u = pque.top().second;
            pque.pop();

            if (havebeen[u])
                continue;
            else
                havebeen[u] = true;

            for (const vector<int> &e : edgeList[u])
            {
                int v = e[0], weight = e[1];
                if (distanceToLastNode[u] + weight < distanceToLastNode[v])
                {
                    distanceToLastNode[v] = distanceToLastNode[u] + weight;
                    pque.push(make_pair(distanceToLastNode[v], v));
                };
            };
        };

        // for (int i = 1; i <= n; i++)
        //     cout << distanceToLastNode[i] << ' ';

        vector<vector<int>> idxAndDistance;
        for (int i = 0; i < n; i++)
            idxAndDistance.push_back({i + 1, distanceToLastNode[i + 1]});
        sort(idxAndDistance.begin(), idxAndDistance.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

        int mod = 1e9 + 7;
        unordered_map<int, int> ans;
        ans[n] = 1;
        for (int i = 0; i < n; i++)
        {
            int node = idxAndDistance[i][0], dis = idxAndDistance[i][1];
            // cout << "node: " << node << " dis: " << dis << endl;
            for (const vector<int> &e : edgeList[node])
            {
                int anotherNode = e[0];
                // cout << anotherNode << ' ';
                if (ans.count(anotherNode) && dis > distanceToLastNode[anotherNode])
                    ans[node] = (ans[node] + ans[anotherNode]) % mod;
            };
            if (ans.count(1))
                return ans[1];
            // cout << endl;
        };
        return -1;
    }
};