class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (const char& stone : stones)
            for (const char& jewel : jewels)
                if (stone == jewel) {
                    ans++;
                    break;
                };
        return ans;
    }
};