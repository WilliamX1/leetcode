class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e5 + 7);
        dp[0] = 0;

        for (auto iter = coins.begin(); iter != coins.end();) {
            if (*iter > amount) {
                iter = coins.erase(iter);
            } else iter++;
        };

        for (int i = 1; i <= amount; i++) {
            for (int& coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                };
            };
        };
        return dp[amount] == 1e5 + 7 ? -1 : dp[amount];
    }
};