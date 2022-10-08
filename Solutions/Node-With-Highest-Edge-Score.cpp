class Solution
{
  public:
    int edgeScore(vector<int> &edges)
    {
        int64_t n = edges.size();
        vector<int64_t> ans(n, 0);
        for (int64_t i = 0; i < n; i++)
            ans[edges[i]] += i;
        int64_t ret = 0, M = ans[0];
        for (int64_t i = 1; i < n; i++)
            if (ans[i] > M)
            {
                M = ans[i];
                ret = i;
            };
        return ret;
    }
};