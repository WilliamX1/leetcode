class Solution {
public:
    int cuttingRope(int n) {
        int64_t mod = 1e9 + 7;
        int64_t a = n / 3, b = n % 3;
        int64_t ans = 1;
        if (n <= 3) ans = n - 1;
        else if (b == 0) while (a-- > 0) ans = (ans * 3) % mod;
        else if (b == 1) {
            while (--a > 0) ans = (ans * 3) % mod;
            ans *= 4;
        } else {
            while (a-- > 0) ans = (ans * 3) % mod;
            ans *= 2;
        };
        return ans % mod;
    }
};