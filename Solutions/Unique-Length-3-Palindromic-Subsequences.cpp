#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int len = s.size();
        vector<vector<int>> dp(26);
        for (int i = 0; i < len; i++)
            dp[s[i] - 'a'].push_back(i);
        
        set<string> ans;
        for (int i = 0; i < 26; i++)
        {
            if (dp[i].size() < 2) continue;
            else {
                int L = dp[i].front(), R = dp[i].back();
                for (int j = 0; j < 26; j++)
                {
                    auto iter = upper_bound(dp[j].begin(), dp[j].end(), L);
                    if (iter != dp[j].end() && *iter < R) {
                        string str = to_string('a' + i) + to_string ('a' + j) + to_string('a' + i);
                        ans.insert(str);
                    };
                }
            };
        };
        return ans.size();
    }
};