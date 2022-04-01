class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, 1e9);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) {
                    dp[mask + (1 << i)] = min(dp[mask + (1 << i)], dp[mask] + (nums1[__builtin_popcount(mask)] ^ nums2[i]));
                };
            };
        };
        return dp[(1 << n) - 1];
    }
};