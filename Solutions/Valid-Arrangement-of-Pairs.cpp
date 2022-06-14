#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, vector<int>> edges;
        unordered_map<int, int> indeg, outdeg;
        for (auto pair : pairs)
        {
            edges[pair[0]].push_back(pair[1]);
            indeg[pair[1]]++;
            outdeg[pair[0]]++;
        };
        int start = pairs[0][0];
        for (const auto &[x, occ] : outdeg)
        {
            if (occ == indeg[x] + 1)
            {
                start = x;
                break;
            };
        };

        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int u) {
            while (!edges[u].empty())
            {
                int v = edges[u].back();
                edges[u].pop_back();
                dfs(v);
                ans.push_back({u, v});
            };
        };

        dfs(start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};