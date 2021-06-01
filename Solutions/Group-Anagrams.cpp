#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (auto str : strs) {
            string ordered_str = str; sort(ordered_str.begin(), ordered_str.end());

            auto iter = m.find(ordered_str);
            if (iter != m.end()) {
                (iter->second).push_back(str);
            } else {
                vector<string> tmp; tmp.push_back(str);
                m.insert(make_pair(ordered_str, tmp));
            };
        };
        
        vector<vector<string>> res;
        auto iter = m.begin();
        while (iter != m.end()) {
            res.push_back(iter->second);
            iter++;
        }
        return res;
    }
};