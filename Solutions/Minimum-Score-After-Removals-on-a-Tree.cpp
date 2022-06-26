class Solution
{
  public:
    int dfs(const vector<int> &nums, const vector<vector<int>> &sons, const int &cur, vector<int> &ans,
            vector<int> &fa_list)
    {
        vector<int> so = sons[cur];
        int tt = 0;
        for (const int &s : so)
        {
            tt ^= dfs(nums, sons, s, ans, fa_list);
            fa_list[s] = cur;
        };
        ans[cur] = tt ^ nums[cur];
        return ans[cur];
    };
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> edgelist;
        for (const vector<int> &edge : edges)
        {
            edgelist[edge[0]].push_back(edge[1]);
            edgelist[edge[1]].push_back(edge[0]);
        };
        vector<vector<int>> sons(n);
        set<int> fa;
        queue<int> pre_fa;
        pre_fa.push(0);
        while (fa.size() < n)
        {
            int p = pre_fa.front();
            fa.insert(p);
            pre_fa.pop();

            for (const int &u : edgelist[p])
                if (!fa.count(u))
                {
                    sons[p].push_back(u);
                    pre_fa.push(u);
                };
        };

        // for (int i = 0; i < n; i++)
        // {
        //     cout << "fa: " << i << endl;
        //     for (const int &j : sons[i])
        //     {
        //         cout << j << ' ';
        //     };
        //     cout << endl;
        // }

        int tot = 0;
        for (int i = 0; i < n; i++)
            tot ^= nums[i];
        // cout << tot << ' ' << endl;
        vector<int> ans(n, 0);
        vector<int> fa_list(n, -1);
        dfs(nums, sons, 0, ans, fa_list);

        vector<vector<bool>> ancestor(n, vector<bool>(n, false)); // i 是不是 j 的 祖先
        for (int i = 0; i < n; i++)
        {
            int cur = fa_list[i];
            while (cur >= 0)
            {
                ancestor[cur][i] = true;
                cur = fa_list[cur];
            };
        };

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << "i: " << i << " j: " << j << ' ' << ancestor[i][j] << endl;
        //     };
        // }

        // for (int i = 0; i < n; i++)
        //     cout << "i : " << i << " ans: " << ans[i] << endl;

        // for (int i = 0; i < n; i++)
        //     cout << "son: " << i << " father: " << fa_list[i] << endl;
        int ret = 0x7fffffff, tot1, tot2, tot3;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // cout << "i: " << i << "j: " << j << " ancestor: " << ancestor[i][j] << endl;
                if (ancestor[i][j])
                {
                    tot1 = ans[i] ^ ans[j];
                    tot2 = ans[j];
                    tot3 = tot ^ ans[i];
                }
                else if (ancestor[j][i])
                {
                    tot1 = ans[i];
                    tot2 = ans[j] ^ ans[i];
                    tot3 = tot ^ ans[j];
                }
                else
                {
                    tot1 = ans[i];
                    tot2 = ans[j];
                    tot3 = tot ^ ans[i] ^ ans[j];
                };
                // cout << tot1 << ' ' << tot2 << ' ' << tot3 << endl;
                ret = min(ret, max(tot1, max(tot2, tot3)) - min(tot1, min(tot2, tot3)));
            }
        }

        return ret;
    }
};