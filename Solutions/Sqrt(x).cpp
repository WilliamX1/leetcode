class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if ((int64_t) mid * (int64_t) mid <= (int64_t) x) left = mid + 1;
            else right = mid - 1;
        };
        return left - 1;
    }
};