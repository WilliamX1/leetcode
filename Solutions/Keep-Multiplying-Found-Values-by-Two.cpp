#include <unordered_map>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, bool> m;
        for (auto num : nums)
            m[num] = true;
        int target = original;
        while (m.find(target) != m.end()) {
            target <<= 1;
        };
        return target;
    }
};