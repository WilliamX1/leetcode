class Solution
{
  public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();

        unordered_map<int, vector<int>> umap;
        unordered_map<int, bool> flags;
        for (int i = 0; i < n; ++i)
        {
            umap[arr[i]].push_back(i);
        };

        vector<int> dp(n, 0x7fffffff);
        queue<vector<int>> que;
        que.push({0, 0}); // i, steps
        dp[0] = 0;

        while (!que.empty())
        {
            vector<int> top = que.front();
            que.pop();

            int i = top[0], steps = top[1];

            // i + 1
            if (i + 1 < n && steps + 1 < dp[i + 1])
            {
                dp[i + 1] = steps + 1;
                que.push({i + 1, steps + 1});
            };

            // i - 1
            if (i - 1 >= 0 && steps + 1 < dp[i - 1])
            {
                dp[i - 1] = steps + 1;
                que.push({i - 1, steps + 1});
            };

            // j, arr[i] == arr[j]
            if (!flags[arr[i]])
            {
                flags[arr[i]] = true;
                for (const int &j : umap[arr[i]])
                {
                    if (i != j && steps + 1 < dp[j])
                    {
                        // cout << j << ' ' << dp[j] << endl;
                        dp[j] = steps + 1;
                        que.push({j, steps + 1});
                    };
                };
            };
        };
        return dp[n - 1];
    }
};