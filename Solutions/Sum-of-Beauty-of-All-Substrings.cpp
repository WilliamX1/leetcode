class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        vector<vector<int>> preSum(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
            preSum[i][s[i] - 'a']++;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < 26; j++)
                preSum[i][j] += preSum[i - 1][j];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int m = 1e5, M = -1e5;
                for (int k = 0; k < 26; k++) {
                    int cur = preSum[j][k] - preSum[i][k] + (s[i] - 'a' == k);
                    if (cur > 0)
                        m = min(m, cur);
                    M = max(M, cur);
                };
                // cout << M << ' ' << m << endl;
                ans += M - m;
            };
        };
        return ans;
    }
};