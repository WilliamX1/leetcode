#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool compare(const string& pre, const string& post) {
        int diff = 0;
        while (diff < pre.size() && pre[diff] == post[diff]) diff++;
        for (int i = diff; i < pre.size(); i++)
            if (pre[i] != post[i + 1]) return false;
        return true;
    };
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a < b : a.size() < b.size();
        });

        vector< set<int> > prefix(words.size());
        vector<int> v;

        int cur_len = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() > cur_len) {
                v.push_back(i);
                cur_len = words[i].size();
            };
        };

        int next = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[v[next]].size() <= words[i].size()) next++;
            if (next >= v.size()) break;
            
            int idx = v[next];
            while (idx < words.size() && words[idx].size() == words[i].size() + 1) {
                if (compare(words[i], words[idx]) == true) prefix[i].insert(idx);
                idx++;
            };
        };

        vector<int> dp(words.size(), 1);
        for (int i = words.size() - 1; i >= 0; i--) {
            for (set<int>::iterator iter = prefix[i].begin(); iter != prefix[i].end(); iter++) {
                dp[i] = max(dp[i], dp[*iter] + 1);
            };
        };
        return *max_element(dp.begin(), dp.end());
    }
};