class Solution
{
  public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
    {
        int n = vals.size();
        vector<vector<int>> v(n);
        for (vector<int> &edge : edges)
        {
            int a = edge[0], b = edge[1];
            v[a].push_back(vals[b]);
            v[b].push_back(vals[a]);
        };

        for (vector<int> &ve : v)
            sort(ve.begin(), ve.end(), greater<int>());

        int ans = -1e9;
        for (int i = 0; i < v.size(); i++)
        {
            int tmp = vals[i];
            for (int j = 0; j < v[i].size() && j < k && v[i][j] >= 0; j++)
                tmp += v[i][j];
            ans = max(ans, tmp);
        };
        return ans;
    }
};