class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n + 1, "");
        dp[1] = "1";
        for (int i = 2; i <= n; i++) {
            string last = dp[i - 1], cur = "";
            int start_pos = 0, end_pos = 0, size = last.size();
            while (end_pos < size) {
                while (last[start_pos] == last[end_pos]) {
                    end_pos++;
                };
                cur += to_string(end_pos - start_pos) + to_string(last[start_pos]);
                start_pos = end_pos;
            };
            cur += to_string(end_pos - start_pos) + to_string(last[start_pos]);
            dp[i] = cur;
        };
        return dp[size - 1];
    }
};