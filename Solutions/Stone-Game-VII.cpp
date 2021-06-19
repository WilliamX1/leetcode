#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix_sum(n, 0); prefix_sum[0] = stones[0];
        for (int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i - 1] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int step = 1; step < n; step++)
            for (int start = 0; start + step < n; start++) {
                int end = start + step;
                dp[start][end] = max(prefix_sum[end] - prefix_sum[start] - dp[start + 1][end], 
                                     prefix_sum[end - 1] - (start == 0 ? 0 : prefix_sum[start - 1]) - dp[start][end - 1]);
            };
        return dp[0][n - 1];
    }
};