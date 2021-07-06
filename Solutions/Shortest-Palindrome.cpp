#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> calNext(string s) {
        vector<int> next(s.size() + 1);
        int i = 0, k = -1;
        next[i] = k;

        while (i < s.size()) {
            if (k == -1 || s[i] == s[k])
                next[++i] = ++k;
            else k = next[k];
        };
        return next;
    };
    string shortestPalindrome(string s) {
        string ori_s = s;
        reverse(s.begin(), s.end());

        vector<int> next = calNext(ori_s);
        
        int i = 0, k = 0;
        int len_s = s.size(), len_k = ori_s.size();
        while (i < len_s && k < len_k) {
            if (k == -1 || ori_s[k] == s[i]) {
                i++;
                k++;
            } else {
                k = next[k];
            };
        };
        return s.substr(0, i - k) + ori_s;
    };
};