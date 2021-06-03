#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> ans(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = i >= j;

        int res = n;
        for (int steps = 1; steps < n; steps++) {
            for (int left = 0; left + steps < n; left++) {
                int right = left + steps;
                ans[left][right] = s[left] == s[right] && ans[left + 1][right - 1];
                if (ans[left][right]) res++;
            };
        };
        return res;
    }
};