class Solution
{
  public:
    int getApples(unordered_map<int, vector<int>> &sons, const vector<bool> &hasApple, vector<bool> &havebeen,
                  const int &root)
    {
        havebeen[root] = true;
        vector<int> son = sons[root];
        if (son.empty())
            return hasApple[root] ? 0 : -1;
        else
        {
            int tot = hasApple[root] ? 0 : -1;
            for (const int &s : son)
            {
                if (havebeen[s])
                    continue;

                int tmp = getApples(sons, hasApple, havebeen, s);
                if (tmp != -1)
                {
                    if (tot == -1)
                        tot = 0;
                    tot += tmp + 2;
                };
            };
            return tot;
        };
    };
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        unordered_map<int, vector<int>> sons;
        for (const vector<int> &edge : edges)
        {
            int from = edge[0], to = edge[1];
            sons[from].push_back(to);
            sons[to].push_back(from);
        };
        vector<bool> havebeen(n, false);
        int ans = getApples(sons, hasApple, havebeen, 0);
        return ans == -1 ? 0 : ans;
    }
};