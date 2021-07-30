#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for (auto ele : adjacentPairs)
        {
            mp[ele[0]].push_back(ele[1]);
            mp[ele[1]].push_back(ele[0]);
        };

        int n = adjacentPairs.size() + 1, begin = 0;
        for (auto ele : mp)
            if ((ele.second).size() == 1) {
                begin = ele.first;
                break;
            };
        vector<int> ans(n);
        ans[0] = begin, ans[1] = mp[begin][0];
        for (int i = 2; i < n; i++)
        {
            auto adj = mp[ans[i - 1]];
            ans[i] = ans[i - 2] == adj[0] ? adj[1] : adj[0];
        };
        return ans;
    }
};