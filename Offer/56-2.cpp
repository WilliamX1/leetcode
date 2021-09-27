class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int64_t ans = 0, base = 3;
        vector<int> dp(32, 0);
        for (auto num : nums) {
            int idx = 0;
            while (num > 0) {
                dp[idx] = (dp[idx] + (num % base)) % base;
                num /= base;
                idx++;
            };
        };
        int64_t tmp = 1;
        for (int i = 0; i < 32; i++) {
            ans += dp[i] * tmp;
            tmp *= 3;
        };
        return ans;
    }
};