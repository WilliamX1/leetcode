class Solution {
public:
    bool isPalindrome(int x) {
        int64_t ans = 0;
        int64_t xx = x;
        while (xx > 0) {
            ans = ans * 10 + xx % 10;
            xx /= 10;
        };
        return ans == (int64_t) x;
    }
};