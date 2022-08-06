class Solution
{
  public:
    int longestCycle(vector<int> &edges)
    {
        unordered_map<int, int> havebeen;
        int n = edges.size(), ans = -1;
        for (int i = 0; i < n; i++)
            if (!havebeen.count(i))
            {
                int start = i;
                int next = i, tt = 0;
                unordered_map<int, bool> umap;
                while (next >= 0 && !havebeen.count(next))
                {
                    umap[next] = true;
                    havebeen[next] = tt;
                    tt++;
                    next = edges[next];
                };
                if (havebeen.count(next) && umap.count(next))
                    ans = max(ans, tt - havebeen[next]);
            };
        return ans;
    }
};