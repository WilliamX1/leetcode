class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int tot = 0, cnt = 0;
        for (const int& sat : satisfaction) {
            if (cnt + sat >= 0) {
                tot += cnt + sat;
                cnt += sat;
            } else break;
        };
        return tot;
    }
};