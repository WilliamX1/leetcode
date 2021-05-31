#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        string ans = "";
        int size = n.size();
        int i;
        if (n[0] == '-') {
            for (i = 1; i < size; i++) {
                if (n[i] - '0' > x) {
                    ans = n.substr(0, i) + to_string(x) + n.substr(i, -1);
                    break;
                };
            };
            if (i == size) {
                ans = n + to_string(x);
            };
        } else {
            for (i = 0; i < size; i++) {
                if (n[i] - '0' < x) {
                    ans = n.substr(0, i) + to_string(x) + n.substr(i, -1);
                    break;
                };
            };
            if (i == size) {
                ans = n + to_string(x);
            };
        };
        return ans;
    }
};