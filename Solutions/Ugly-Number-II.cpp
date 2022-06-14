#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
  public:
    int nthUglyNumber(int n)
    {
        /*暴力遍历*/
        // vector<long long> res;
        // long long size = 0;
        // long long idx = 1;
        // const int N = 1690;
        // while (size < n) {
        //     long long x = idx;
        //     while (x % 2 == 0) x /= 2;
        //     while (x % 3 == 0) x /= 3;
        //     while (x % 5 == 0) x /= 5;
        //     if (x == 1) {
        //         res.push_back(idx);
        //         size++;
        //     }
        //     idx++;
        // };
        // return res.back();
        /*动态规划*/
        int p2 = 1, p3 = 1, p5 = 1; //数组下标指针
        int *dp = new int[n + 1];
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int num2 = 2 * dp[p2], num3 = 3 * dp[p3], num5 = 5 * dp[p5];
            if (num2 <= num3 && num2 <= num5)
            {
                p2++;
                dp[i] = num2;
            };
            if (num3 <= num2 && num3 <= num5)
            {
                p3++;
                dp[i] = num3;
            };
            if (num5 <= num2 && num5 <= num3)
            {
                p5++;
                dp[i] = num5;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution S;
    printf("%lld", S.nthUglyNumber(1690));
    return 0;
}