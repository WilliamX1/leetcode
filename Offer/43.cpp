class Solution {
public:
    int countDigitOne(int n) {
        int64_t ans = 0;
        int64_t num = 0; /* 共有几位 */
        int64_t tmp_n = n;
        int64_t c = 0;

        while (tmp_n > 0) {
            tmp_n /= 10;
            num++;
        };

        for (int64_t i = 0; i < num; i++)
        {
            c = pow(10, i);
            tmp_n = n;
            if (tmp_n >= c * 10) {
                ans += (tmp_n / (c * 10)) * c;
            };
            tmp_n %= c * 10;
            if (tmp_n >= c * 2) {
                ans += c;
            } else if (tmp_n >= c) {
                ans += tmp_n - c + 1;
            } else continue;
        };
        return ans;
    }
};