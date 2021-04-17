#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*动态规划*/
        // const int len = s.length();
        // bool dp[len][len]; memset(dp, 0, sizeof(dp));
        // for (int i = 0; i < len; i++)
        //     for (int j = 0; j <= i; j++)
        //         dp[i][j] = true;
        
        // int left_idx = 0, right_idx = 0;
        // for (int k = 1; k < len; k++)
        //     for (int i = 0; i + k < len; i++)
        //         if (s[i] == s[i + k] && dp[i + 1][i + k - 1]) {
        //             dp[i][i + k] = true;
        //             left_idx = i;
        //             right_idx = i + k;
        //         };
        // return s.substr(left_idx, right_idx - left_idx + 1);
        /*中心扩展*/
        const int _size = s.length();
        int left_idx = 0, right_idx = 0;
        /*奇数子字符串时*/
        for (int i = 0; i < _size; i++)
        {   
            int j = 1;
            for (; 0 <= i - j && i + j < _size; j++)
                if (s[i - j] != s[i + j]) break;
            if (2 * (j - 1) > right_idx - left_idx) {
                left_idx = i - j + 1;
                right_idx = i + j - 1;
            };
        }
        /*偶数子字符串时*/
        for (int i = 0; i < _size; i++)
        {
            int j = 1;
            for (; 0 <= i - j && i + j - 1 < _size; j++)
                if (s[i - j] != s[i + j - 1]) break;
            if (2 * (j - 1) > right_idx - left_idx) {
                left_idx = i - j + 1;
                right_idx = i + j - 2;
            };
        };
        return s.substr(left_idx, right_idx - left_idx + 1);
    }
};

int main()
{
    Solution S;
    std::cout << S.longestPalindrome("abcbe");
    return 0;
}