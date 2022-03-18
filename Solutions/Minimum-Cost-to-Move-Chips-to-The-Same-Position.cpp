class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for (const int& pos : position)
            if (pos & 1) odd++;
            else even++;
        return min(even, odd);
    }
};