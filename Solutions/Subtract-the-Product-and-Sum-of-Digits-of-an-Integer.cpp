class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, plus = 0;
        while (n > 0) {
            mul *= n % 10;
            plus += n % 10;
            n /= 10;
        };
        return mul - plus;
    }
};