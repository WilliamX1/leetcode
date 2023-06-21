class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int idx = 0, n = s.size(), ans = 0;

        while (idx < n) {
            int zeros = 0, ones = 0;
            while (idx < n && s[idx] == '0') {
                zeros++;
                idx++;
            };
            while (idx < n && s[idx] == '1') {
                ones++;
                idx++;
            };
            ans = max(ans, 2 * min(zeros, ones));
        };
        return ans;
    }
};