class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = n & 1;
        n >>= 1;
        while (n > 0) {
            if (flag == (n & 1)) return false;
            else {
                flag = n & 1;
                n >>= 1;
            };
        };
        return true;
    }
};