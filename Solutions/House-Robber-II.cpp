#include <vector>
#include <memory.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*如果nums为空则返回*/
        if (nums.empty()) return 0;
        /*动态规划*/
        const int _size = nums.size();
        int dp[_size][2][2]; //第一维代表第几项，第二维为0代表不含该项，第三维代表是否含有第一项
        memset(dp, 0, sizeof(dp));
        dp[0][0][1] = dp[0][1][0] = 0; //矛盾
        dp[0][0][0] = 0;
        dp[0][1][1] = nums[0];

        for (int i = 1; i < _size; i++) {
            dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);
            dp[i][1][0] = dp[i - 1][0][0] + nums[i];
            dp[i][1][1] = dp[i - 1][0][1] + nums[i];
        };
        return max(max(dp[_size - 1][0][0], dp[_size - 1][0][1]), max(dp[_size - 1][1][0], dp[0][1][1]));
    }
};

int main()
{
    Solution S;
    vector<int> v = {2, 3, 2};
    printf("%d", S.rob(v));
    return 0;
}