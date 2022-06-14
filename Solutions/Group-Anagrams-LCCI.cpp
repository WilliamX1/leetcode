#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<vector<int>, vector<int>> m;
        int len = strs.size();
        for (int i = 0; i < len; i++)
        {
            vector<int> key(26);
            for (auto ch : strs[i])
                key[ch - 'a']++;
            auto iter = m.find(key);
            if (iter != m.end())
                iter->second.push_back(i);
            else
            {
                vector<int> v = {i};
                m.insert(make_pair(key, v));
            };
        };
        vector<vector<string>> ans;
        for (auto ele : m)
        {
            vector<string> next;
            auto s = ele.second;
            for (auto x : s)
                next.push_back(strs[x]);
            ans.push_back(next);
        };
        return ans;
    }
};