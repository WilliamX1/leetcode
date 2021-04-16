#include <string>
#include <stdio.h>
#include <memory.h>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        const int len = s1.length();
        /*dp[i][j][len]表示字符串s1从下标i开始，字符串s2从下标j开始，长度为len能否相互转换*/
        bool dp[30][30][30 + 1];  memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                dp[i][j][1] = s1[i] == s2[j];
        /*动态规划*/
        for (int k = 2; k <= len; k++)
            for (int i = 0; i <= len - k; i++)
                for (int j = 0; j <= len - k; j++)
                    for (int idx = 1; idx < k; idx++) 
                    {
                        /*第一种情况，前前转换且后后转换*/
                        if (!dp[i][j][k]) 
                            dp[i][j][k] = dp[i][j][idx] & dp[i + idx][j + idx][k - idx];
                        /*第二种情况，前后转换且后前转换*/
                        if (!dp[i][j][k]) 
                            dp[i][j][k] = dp[i][j + k - idx][idx] & dp[i + idx][j][k - idx]; 
                    }
        return dp[0][0][len];
    }
};

int main()
{
    Solution S;
    printf("%d", S.isScramble("abc", "bca"));
    return 0;
}