class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = sqrt(area), W = -1;
        while (L > 0) {
            if (area % L == 0) {
                W = area / L;
                break;
            };
            L++;
        };
        if (W > L) swap(W, L);
        return {L, W};
    }
};