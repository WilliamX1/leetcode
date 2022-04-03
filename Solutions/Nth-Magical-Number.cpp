class Solution {
public:
    long long gcd(long long a, long long b) {
        int temp = 0;
        while (b != 0) {
            temp = a;
            a = b;
            b = temp % b;
        };
        return a;
    };
    long long count(long long a, long long b, long long mid) {
        return mid / a + mid / b - mid / ((a * b) / gcd(a, b));
    };
    int nthMagicalNumber(int n, int a, int b) {
        long long left = 1, right = 1e18 + 1, mid, mod = 1e9 + 7;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (count(a, b, mid) >= n) right = mid - 1;
            else left = mid + 1;
        };
        return left % mod;
    }
};