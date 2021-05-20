#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node {
        string val;
        int cnt;
        node(string v, int c) : val(v), cnt(c) {};
        node() {};
        static bool compare(node a, node b) {
            if (a.cnt == b.cnt) return a.val < b.val;
            else return a.cnt > b.cnt;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        auto iter = words.begin();
        while (iter != words.end()) {
            if (m.find(*iter) != m.end()) {
                m[*iter]++;
            } else m.insert(make_pair(*iter, 1));
            iter++;
        };
        
        /* 转换 */
        vector<node> v;
        auto cursor = m.begin();
        while (cursor != m.end()) {
            v.push_back(node(cursor->first, cursor->second));
            cursor++;
        };
        sort(v.begin(), v.end(), node::compare);
        vector<string> ans;
        auto cur = v.begin();
        while (cur != v.end() && k-- > 0) {
            ans.push_back(cur->val);
            cur++;
        }
        return ans;
    }
};

int main()
{
    vector<string> v;
    v.push_back("the");
    v.push_back("day");
    v.push_back("is");
    v.push_back("sunny");
    v.push_back("the");
    v.push_back("the");
    v.push_back("the");
    v.push_back("sunny");
    v.push_back("is");
    v.push_back("is");
    Solution S;
    S.topKFrequent(v, 4);
    return 0;
}