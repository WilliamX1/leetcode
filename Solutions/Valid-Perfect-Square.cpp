class Solution {
public:
    bool isPerfectSquare(int num) {
        int t = sqrt(num);
        return t * t == num;
    }
};