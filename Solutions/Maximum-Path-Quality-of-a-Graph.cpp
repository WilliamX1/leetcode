class Solution
{
  public:
    void dfs(const vector<int> &values, const int &n, int node, const vector<vector<vector<int>>> &edgelist,
             set<int> &havebeen, int moretime, int cur_val, int &ans)
    {
        bool flag = false;
        if (moretime >= 0)
        {
            if (!havebeen.count(node))
            {
                flag = true;
                cur_val += values[node];
            }
            if (node == 0)
                ans = max(ans, cur_val);
        }
        else
            return;

        for (const vector<int> &edge_time : edgelist[node])
        {
            int edge_v = edge_time[0], time = edge_time[1];

            if (flag)
                havebeen.insert(node);

            dfs(values, n, edge_v, edgelist, havebeen, moretime - time, cur_val, ans);

            if (flag)
                havebeen.erase(node);
        };
    }
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        int n = values.size();
        vector<vector<vector<int>>> edgelist(n);
        for (const vector<int> &edge : edges)
        {
            edgelist[edge[0]].push_back({edge[1], edge[2]});
            edgelist[edge[1]].push_back({edge[0], edge[2]});
        };
        set<int> havebeen;
        int ans = 0;
        dfs(values, n, 0, edgelist, havebeen, maxTime, 0, ans);
        return ans;
    }
};