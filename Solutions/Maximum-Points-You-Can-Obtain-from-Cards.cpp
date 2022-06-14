class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(n, 0);
        prefix[0] = cardPoints[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + cardPoints[i];
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, (i > 0 ? prefix[i - 1] : 0) + (prefix[n - 1] - (i > 0 ? prefix[n - 1 - (k - i)] : prefix[n - 1 - (k - i) + 1] - cardPoints[n - 1 - (k - i) + 1])));
        };
        return ans;
    }
};