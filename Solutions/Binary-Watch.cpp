class Solution {
public:
    int count(int x) {
        int ans = 0;
        while (x > 0) {
            x -= near(x);
            ans++;
        };
        return ans;
    };
    int near(int x) {
        if (x >= 32) return 32;
        else if (x >= 16) return 16;
        else if (x >= 8) return 8;
        else if (x >= 4) return 4;
        else if (x >= 2) return 2;
        else return 1;
    };
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<string>> dp(11, vector<string>());
        for (int i = 0; i <= 11; i++)
            for (int j = 0; j <= 59; j++)
                dp[count(i) + count(j)].push_back(to_string(i) + ':' + (j <= 9 ? '0' + to_string(j) : to_string(j)));
        return dp[turnedOn];
    }
}; 