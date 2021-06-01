#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        int m, M, i = 0;
        while (i < n) {
            m = intervals[i][0];
            M = intervals[i][1];
            int j = i + 1;
            for (; j < n; j++) {
                if (m <= intervals[j][0] && intervals[j][0] <= M 
                ||  m <= intervals[j][1] && intervals[j][1] <= M) {
                    m = min(m, intervals[j][0]);
                    M = max(M, intervals[j][1]);
                } else break;
            };
            res.push_back({m, M});
            i = j;
        };
        return res;
    }
};