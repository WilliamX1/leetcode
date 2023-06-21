class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, tmp = 0;
        for (char c : s) {
            if (c == 'L') tmp++;
            else tmp--;
            if (tmp == 0) count++;
        };
        return count;
    }
};