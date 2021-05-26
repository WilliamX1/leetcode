#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = count(s.begin(), s.end(), '1');
        if (abs(cnt0 - cnt1) > 1) return -1;
        else {
            set<int> v;
            int n = s.size(), ans = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') v.insert(i);
            };
            if (cnt0 - cnt1 == 1) { // 那么两边都需要 0
                for (int i = 0; i < n; i += 2)
                    if (v.find(i) == v.end())
                        ans++; 
            } else if (cnt0 - cnt1 == -1) { // 那么两边都是 1
                for (int i = 1; i < n; i += 2)
                    if (v.find(i) == v.end())
                        ans++;
            } else {
                int tmp = 0;
                for (int i = 0; i < n; i += 2)
                    if (v.find(i) == v.end())
                        tmp++; 
                for (int i = 1; i < n; i += 2)
                    if (v.find(i) == v.end())
                        ans++;
                ans = min(ans, tmp);
            };
            return ans;
        }
    }
};