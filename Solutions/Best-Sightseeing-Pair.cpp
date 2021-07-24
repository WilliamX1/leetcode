class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int prev_max = 0;
        int ans = 0, len = values.size();
        for (int i = 0; i < len; i++)
        {
            ans = max(ans, values[i] - i + prev_max);
            prev_max = max(prev_max, values[i] + i);
        };
        return ans;
    }
};