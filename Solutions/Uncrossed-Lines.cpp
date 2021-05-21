#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /* 动态规划 */
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        /* dp[i][j] = max(dp[k][s]) + whether num1[i] == num2[j]  where k = 0...i - 1, s = 0...j - 1 */
        int i, j;
        for (i = 1; i <= n1; i++)
            for (j = 1; j <= n2; j++)
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return dp[n1][n2];
    }
};
int main()
{
    vector<int> num1 = {1,3,7,1,7,5};
    vector<int> num2 = {1,9,2,5,1};
    Solution S;
    printf("%d", S.maxUncrossedLines(num1, num2));
    return 0;
}