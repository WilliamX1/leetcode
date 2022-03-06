#include <vector>

using namespace std;
using LL = long long;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0);
        nums.push_back(2e9 + 7);
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int start = nums[i], end = nums[i + 1], minus = max(0, end - start - 1);
            if (k > minus) {
                ans += (LL) (start + end) * (LL) minus / 2;
                k -= minus;
            } else {
                ans += (LL) (start + 1 + start + k) * (LL) k / 2;
                break;
            };
        };
        return ans;
    }
};