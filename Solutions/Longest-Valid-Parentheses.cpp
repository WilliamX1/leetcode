#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> v; v.push_back(-1);
        int n = s.size();

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                v.pop_back();
                if (!v.empty()) {
                    res = max(res, i - v.back());
                } else v.push_back(i);
            } else {
                v.push_back(i);
            };
        };
        return res;
    }
};

int main()
{
    Solution S;
    cout << S.longestValidParentheses("()(()");
    return 0;
}