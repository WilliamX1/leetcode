class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        };
        sort(capacity.begin(), capacity.end());

        int index = 0;
        while (additionalRocks > 0) {
            if (index < n && capacity[index] <= additionalRocks) {
                additionalRocks -= capacity[index];
                index++;
            } else break;
        };
        return index;
    }
};