class Solution {
public:
    int translateNum(int num) {
        string str_num = to_string(num);
        int len = str_num.size();
        vector<int> dp(len, 0); dp[0] = 1;

        if (len == 1) return 1;
        else {
            int num = (str_num[0] - '0') * 10 + str_num[1] - '0';
            dp[1] = 1 + (10 <= num && num <= 25);
        };

        for (int i = 2; i < len; i++) {
            dp[i] = dp[i - 1];
            int num =  (str_num[i - 1] - '0') * 10 + str_num[i] - '0';
            dp[i] += (10 <= num && num <= 25) ? dp[i - 2] : 0;
        };
        return dp[len - 1];
    }
};