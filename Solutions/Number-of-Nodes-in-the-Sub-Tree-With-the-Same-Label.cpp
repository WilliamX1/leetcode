#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    const int N = 26;
    vector<int> dfs(int root, const vector<vector<int>> &sons, vector<int> &ans, const string &labels)
    {
        vector<int> res(N, 0);
        for (const int &son : sons[root])
        {
            vector<int> count = dfs(son, sons, ans, labels);
            for (int i = 0; i < N; i++)
                res[i] += count[i];
        };
        res[labels[root] - 'a']++;
        ans[root] = res[labels[root] - 'a'];
        return res;
    };
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> edges_map(n);
        for (const vector<int> &e : edges)
        {
            edges_map[e[0]].push_back(e[1]);
            edges_map[e[1]].push_back(e[0]);
        };
        vector<bool> havebeen(n, false);
        vector<vector<int>> sons(n);
        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int root = q.front();
            q.pop();

            havebeen[root] = true;
            for (const int &son : edges_map[root])
            {
                if (!havebeen[son])
                {
                    sons[root].push_back(son);
                    q.push(son);
                };
            };
        };

        vector<int> ans(n, 0);
        dfs(0, sons, ans, labels);
        return ans;
    }
};