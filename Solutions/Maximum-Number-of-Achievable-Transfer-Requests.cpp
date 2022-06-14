class Solution
{
  public:
    void dfs(const int &n, const vector<vector<int>> &requests, const int idx, const vector<int> &v, const int tot,
             int &ans)
    {
        if (idx == requests.size())
        {
            bool flag = true;
            for (int i = 0; i < n; i++)
                if (v[i] != 0)
                    flag = false;
            if (flag)
                ans = max(ans, tot);
            return;
        };

        vector<int> vack = v;
        vack[requests[idx][0]]--;
        vack[requests[idx][1]]++;
        dfs(n, requests, idx + 1, vack, tot + 1, ans);

        dfs(n, requests, idx + 1, v, tot, ans);
    };
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        vector<int> v(n, 0);
        int ans = 0;
        dfs(n, requests, 0, v, 0, ans);
        return ans;
    }
};