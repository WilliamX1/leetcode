class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int tot = 0;
            while (num > 0) {
                tot += num % 10;
                num /= 10;
            };
            num = tot;
        };
        return num;
    }
};