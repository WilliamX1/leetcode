class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num != 0) {
            ans++;
            if (num & 1) num--;
            else num >>= 1;
        };
        return ans;
    }
};