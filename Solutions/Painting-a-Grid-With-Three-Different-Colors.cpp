#include <bits/stdc++.h>

using namespace std;

/* 未完成 */

class Solution {
public:
    bool check(int x, int m) {
        int last = -1;
        for (int i = 0; i < m; i++) {
            if (x % 3 == last) return false;
            last = x % 3;
            x /= 3;
        };
        return true;
    };
    bool check_n(int x, int y, int m) {
        for (int i = 0; i < m; i++) {
            if (x % 3 == y % 3) return false;
            x /= 3, y /= 3;
        };
        return true;
    };
    int colorTheGrid(int m, int n) {
        int64_t mod = 1e9 + 7;
        int up = 1;
        for (int i = 0; i < m; i++) up *= 3;

        vector<vector<int64_t>> dp(n, vector<int64_t>(up, 0));

        for (int i = 0; i < up; i++)
            if (check(i, m)) dp[0][i]++;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < up; j++)
            {
                if (check(j, m))
                    for (int k = 0; k < up; k++)
                        if (check(k, m) && check_n(j, k, m))
                            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            };
        int64_t ans = 0;
        for (int i = 0; i < up; i++)
            ans += []
    }
};