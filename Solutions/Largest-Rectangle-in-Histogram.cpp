#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack< vector<int> > s; // [idx, val]

        heights.push_back(0);
        heights.insert(heights.begin(), 0);

        int n = heights.size();
        vector<int> v_pos(n, 1), v_neg(n, 1);      
        for (int i = 0; i < n; i++) {
            if (!s.empty() && s.top()[1] > heights[i]) {
                vector<int> t = s.top();
                while (!s.empty() && s.top()[1] > heights[i]) {
                    v_pos[s.top()[0]] = t[0] - s.top()[0] + 1;
                    s.pop();
                };  
            };
            vector<int> v;
            v.push_back(i);
            v.push_back(heights[i]);
            s.push(v);
        };

        /* clear */
        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; i--) {
            if (!s.empty() && s.top()[1] > heights[i]) {
                vector<int> t = s.top();
                while (!s.empty() && s.top()[1] > heights[i]) {
                    v_neg[s.top()[0]] = s.top()[0] - t[0] + 1;
                    s.pop();
                };  
            };
            vector<int> v;
            v.push_back(i);
            v.push_back(heights[i]);
            s.push(v);
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // cout << v_pos[i] << ' ' << v_neg[i] << ' ' << heights[i] << endl;
            ans = max(ans, (v_pos[i] + v_neg[i] - 1) * heights[i]);
        };

        return ans;
    }
};