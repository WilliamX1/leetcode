#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    struct node {
        string str;
        int tot;
        node() {};
        node(string s, int i) : str(s), tot(i) {};
    };
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_set<int> prev_all, cur, next;

        next.insert(id);

        while (level-- > 0) {
            cur = next;
            next.clear();

            for (const auto& num : cur)
                prev_all.insert(num);

            for (const auto& num : cur)
                for (const auto& fri : friends[num])
                    if (!prev_all.count(fri))
                        next.insert(fri);
        };

        unordered_map<string, int> m;
        for (const auto& num : next)
            for (const auto& ch : watchedVideos[num])
                m[ch]++;
        
        vector<node> v;
        for (const auto& pair : m)
            v.push_back(node(pair.first, pair.second));
        sort(v.begin(), v.end(), [](const node& a, const node& b) {
            return a.tot == b.tot ? a.str < b.str : a.tot < b.tot;
        });

        vector<string> ans;
        for (const auto& node : v) {
            // cout << node.tot << ' ';
            ans.push_back(node.str);
        };
        return ans;
    }
};