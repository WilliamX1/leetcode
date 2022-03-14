class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& matrix) {
        sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int m = matrix.size();
        vector<int> dp(m + 1, 0x7fffffff);
        dp[0] = 0;

        for (int i = 0; i < m; i++) {
            if (matrix[i][1] > dp[i]) dp[i + 1] = matrix[i][1];
            else {
                int left = 0, right = m, mid;
                while (left <= right) {
                    mid = (left + right) >> 1;
                    if (matrix[i][1] > dp[mid]) left = mid + 1;
                    else right = mid - 1;
                };
                dp[left] = min(dp[left], matrix[i][1]);
            };
        };

        int ans = 0;
        for (int i = 0; i <= m; i++)
            if (dp[i] != 0x7fffffff) 
                ans = max(ans, i);
    
        return ans;
    }
};