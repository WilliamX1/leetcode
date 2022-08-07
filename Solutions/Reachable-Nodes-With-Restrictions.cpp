class Solution
{
  public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        unordered_map<int, vector<int>> edgelist;
        unordered_map<int, bool> restrictedlist;
        for (const vector<int> &edge : edges)
        {
            edgelist[edge[0]].push_back(edge[1]);
            edgelist[edge[1]].push_back(edge[0]);
        };
        for (const int &r : restricted)
            restrictedlist[r] = true;
        vector<bool> ans(n, false);
        ans[0] = true;
        deque<int> dq;
        dq.push_back(0);
        while (!dq.empty())
        {
            int t = dq.front();
            dq.pop_front();

            for (const int &node : edgelist[t])
            {
                if (!ans[node] && !restrictedlist[node])
                {
                    ans[node] = true;
                    dq.push_back(node);
                };
            };
        };
        int ret = accumulate(ans.begin(), ans.end(), 0);
        return ret;
    }
};