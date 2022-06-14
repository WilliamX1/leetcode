#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> ans;
    void dfs(vector<int> &candidates, int n, int idx, int target, vector<int> &combine)
    {
        if (target == 0)
        {
            ans.emplace_back(combine);
        }
        else
        {
            if (idx < n - 1)
                dfs(candidates, n, idx + 1, target, combine);
            if (target >= candidates[idx])
            {
                combine.emplace_back(candidates[idx]);
                dfs(candidates, n, idx, target - candidates[idx], combine);
                combine.pop_back();
            };
        };
        return;
    };
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> combine;
        dfs(candidates, candidates.size(), 0, target, combine);
        return ans;
    }
};