class Solution {
public:
    int nthUglyNumber(int n) {
        int ptr2 = 1, ptr3 = 1, ptr5 = 1;
        vector<int> dp(n + 1, 0); dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int num2 = dp[ptr2] * 2, num3 = dp[ptr3] * 3, num5 = dp[ptr5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) ptr2++;
            if (dp[i] == num3) ptr3++;
            if (dp[i] == num5) ptr5++;
        };
        return dp[n];
    }
};