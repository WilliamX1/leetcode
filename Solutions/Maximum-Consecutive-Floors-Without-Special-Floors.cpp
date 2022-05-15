class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        bottom--;
        top++;
        int ans = 0;
        for (const int & spec : special) {
            if (bottom < spec && spec < top) {
                ans = max(ans, spec - bottom - 1);
                bottom = spec;
            };
        };
        ans = max(ans, top - bottom - 1);
        return ans;
    }
};