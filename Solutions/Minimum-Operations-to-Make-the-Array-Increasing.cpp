#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int tmp = nums.front();
        int res = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] <= tmp) {
                res += tmp - nums[i] + 1;
                tmp++;
            } else tmp = nums[i];
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> v = {1, 5, 2, 4, 1};
    S.minOperations(v);
    return 0;
}