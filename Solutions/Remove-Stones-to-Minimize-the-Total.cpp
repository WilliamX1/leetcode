class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int len = *max_element(piles.begin(), piles.end());
        vector<int> dp(len + 1, 0);
        for (auto ele : piles) dp[ele]++;

        int idx = len;
        while (k-- > 0) {
            while (idx >= 0 && !dp[idx]) idx--;
            if (idx < 0) break;
            else {
                dp[idx]--;
                dp[(idx + 1) / 2]++;
            };
        };
        int ans = 0;
        for (int i = 1; i <= len; i++)
            ans += i * dp[i];
        return ans;
    }
};