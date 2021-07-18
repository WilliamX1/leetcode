class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        rungs.insert(rungs.begin(), 0);
    
        int len = rungs.size();
        vector<int> dp(len, 0);
        for (int i = 1; i < len; i++)
            dp[i] = (rungs[i] - rungs[i - 1] - 1) / dist + dp[i - 1];
        return dp[len - 1];
    }
};