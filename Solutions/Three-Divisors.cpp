class Solution {
public:
    bool isThree(int n) {
        int max = n >> 1, ans = 3;
        for (int i = 1; i < max; i++) {
            if (n % i == 0) {
                ans--;
                if (!ans) return false;
            };
        };
        return ans == 1;
    }
};