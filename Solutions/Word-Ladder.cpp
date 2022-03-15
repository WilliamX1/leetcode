class Solution {
public:
    int OK(const string& word1, const string& word2, const int& k) {
        int tot = 0;
        for (int i = 0; i < k; i++)
            if (word1[i] != word2[i]) tot++;
        if (tot <= 1) return tot;
        else return 1e9 + 7;
    };
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sort(wordList.begin(), wordList.end());

        int n = wordList.size(), k = endWord.size(), cnt = 0;
        vector<int> dp(n, 1e9 + 7);

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                flag = true;
                dp[i] = 1;
            };
        };
        if (!flag) return 0;
        
        int ttt = 0;
        do {
            flag = false;
            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i - j >= 0) {
                        cnt = OK(wordList[i], wordList[i - j], k);
                        if (dp[i - j] + cnt < dp[i]) {
                            dp[i] = dp[i - j] + cnt;
                            flag = true;
                        };
                    };
                    if (i + j < n) {
                        cnt = OK(wordList[i], wordList[i + j], k);
                        if (dp[i + j] + cnt < dp[i]) {
                            dp[i] = dp[i + j] + cnt;
                            flag = true;
                        };
                    };
                };
            };
        } while (flag);

        for (int i = 0; i < n; i++)
            cout << wordList[i] << ' ' << dp[i] << ' ';

        int ans = 1e9 + 7;
        for (int i = 0; i < n; i++) 
            ans = min(ans, dp[i] + OK(wordList[i], beginWord, k));
        return ans == 1e9 + 7 ? 0 : ans;
    }
};