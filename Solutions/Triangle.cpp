#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector< vector<int> > dp(n, vector<int>(n, 0x7fffffff));
        dp[0][0] = triangle[0][0];

        int res = 0x7fffffff;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                if (j < i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);

                if (i == n - 1) res = min(res, dp[i][j]);
            };
        };
        return res;
    }
};