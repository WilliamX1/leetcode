#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool res = true;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0) return 0;
            else res ^= nums[i] < 0;
        return res == true ? 1 : -1;
    }
};