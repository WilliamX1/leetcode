#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();

        int M = 1;
        for (int i = 1; i <= numSlots; i++) M *= 3;
        vector< vector<int> > dp(n + 1, vector<int>(M, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= M; j++) {
                int t = j, w = 1;
                for (int k = 1; k <= numSlots; k++) {
                    if (t % 3) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + (k & nums[i - 1]));
                    };
                    t /= 3;
                    w *= 3;
                };
            };
        };
        return *max_element(dp[n].begin(), dp[n].end());
    }
};