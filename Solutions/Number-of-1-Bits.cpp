class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tot = 0;
        for (int i = 0; i < 32; i++)
            tot += (n >> i) & 1;
        return tot;
    }
};