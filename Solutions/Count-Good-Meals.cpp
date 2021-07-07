#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<uint64_t, uint64_t> store;
        set<uint64_t> s;
        for (auto deliciou : deliciousness)
        {
            auto iter = store.find(deliciou);
            if (iter == store.end()) 
                store.insert(make_pair(deliciou, 1));
            else iter->second++;
            s.insert(deliciou);
        };

        const uint64_t N = 1e9;
        const uint64_t mod = 1e9 + 7;
        uint64_t ans = 0;
        for (uint64_t i = 1; i <= N; i <<= 1) {
            for (auto ele : s) {
                auto iter = store.find(i - ele);
                if ((ele << 1) == i) {
                    ans += iter->second * (iter->second - 1);
                } else {
                    if (iter != store.end()) {
                        ans += store.find(ele)->second * iter->second;
                    };
                };
            };
        };
        ans >>= 1;
        return ans % mod;
    }
};
