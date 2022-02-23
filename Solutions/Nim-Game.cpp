class Solution {
public:
    bool canWinNim(int n) {
        return n & 1 || (n >> 1) & 1;
    }
};