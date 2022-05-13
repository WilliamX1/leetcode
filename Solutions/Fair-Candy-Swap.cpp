class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice_tot = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bob_tot = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int minus = (alice_tot - bob_tot) >> 1;
        
        unordered_map<int, bool> bob_map;
        for (const int& num : bobSizes)
            bob_map[num] = true;
        for (const int& num : aliceSizes)
            if (bob_map[num - minus]) {
                return {num, num - minus};
            };
        return {};
    }
};