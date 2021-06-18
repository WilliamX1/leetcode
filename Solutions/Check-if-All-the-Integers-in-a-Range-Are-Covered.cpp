#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int nmax = 50;
        vector<bool> flag(nmax, false);
        for (auto range : ranges) {
            for (int start = range[0]; start <= range[1]; start++) {
                flag[start] = true;
            };
        };
        for (int i = left; i <= right; i++)
            if (!flag[i]) return false;
        return true;
    }
};