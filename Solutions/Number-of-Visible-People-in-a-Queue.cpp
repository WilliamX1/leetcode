class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        vector<int> v(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() < heights[i]) {
                v[i]++;
                stk.pop();
            };
            if (!stk.empty()) v[i]++;
            stk.push(heights[i]);
        };
        return v;
    }
};