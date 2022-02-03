class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        do {
            int x = a & 1, y = b & 1, z = c & 1;
            if ((x | y) == z) {} 
            else if (z == 0 && x == 1 && y == 1) cnt += 2;
            else cnt++;
            a >>= 1;
            b >>= 1;
            c >>= 1;
        } while ((a | b) != c);
        return cnt;
    }
};