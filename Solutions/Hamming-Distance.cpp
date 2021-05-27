#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0, xy = x ^ y;
        while (xy) {
            if (xy & 1) ans++;
            xy >>= 1;
        };
        return ans;
    }
};