class Solution {
public:
    int countEven(int num) {
        int cnt = 0;
        for (int i = 1; i <= num; i++) {
            int tot = 0, tmp = i;
            while (tmp > 0) {
                tot += tmp % 10;
                tmp /= 10;
            };
            if (tot % 2 == 0) cnt++;
        };
        return cnt;
    }
};