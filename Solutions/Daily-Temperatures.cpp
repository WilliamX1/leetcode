#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct node
    {
        /* data */
        int val;
        int idx;
        node(){};
        node(int v, int i) : val(v), idx(i) {};
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<node> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top().val < temperatures[i]) {
                node del = stk.top();
                stk.pop();
                ans[del.idx] = i - del.idx;
            };
            stk.push(node(temperatures[i], i));
        };
        return ans;
    }
};