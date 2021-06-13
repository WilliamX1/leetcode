// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int64_t left = 0, right = n, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (isBadVersion(mid)) right = mid - 1;
            else left = mid + 1;
        };
        return left;
    }
};