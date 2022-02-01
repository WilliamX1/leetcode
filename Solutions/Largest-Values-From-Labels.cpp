#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int len = values.size();
        vector< vector<int> > v(len, vector<int>(2, 0));
        unordered_map<int, int> label_map;
        for (int i = 0; i < len; i++) {
            v[i][0] = values[i];
            v[i][1] = labels[i];
            label_map[labels[i]] = 0;
        };
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
        });

        int ans = 0, idx = 0;
        while (numWanted-- > 0) {
            while (idx < len && label_map[v[idx][1]] == useLimit) idx++;

            if (idx >= len) break;
            else {
                label_map[v[idx][1]]++;
                ans += v[idx][0];
                idx++;
            };
        };
        return ans;
    }
};