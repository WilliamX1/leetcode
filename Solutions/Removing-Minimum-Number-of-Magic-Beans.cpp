#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int len = beans.size();
        vector<LL> prefix(len + 1, 0);
        for (int i = 0; i < len; i++) prefix[i + 1] = prefix[i] + (LL) beans[i];

        LL ans = 0x7fffffffffffffff;
        for (int i = 0; i < len; i++) {
            LL tot = prefix[len] - (LL) beans[i] * (len - i);
            if (tot < ans) ans = tot;
        };
        return ans;
    }
};