class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() == b.size() ? a < b : a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, false);
        for (int i = 0; i < n; i++)
            if (words[i].size() == 1) dp[i] = true;
            else break;
        for (int i = 0; i < n; i++)
            for (int j = i - 1; j >= 0; j--) {
                if (words[i].size() > words[j].size() + 1) break;
                else if (dp[j] && words[i].substr(0, words[j].size()) == words[j]) {
                    dp[i] = true;
                    continue;
                } else {}
            };
        int len = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (dp[i] && words[i].size() > len) {
                len = words[i].size();
                ans = words[i];
            };
        };
        return ans;
    }
};