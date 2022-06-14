#include <iostream>

using LL = long long;

class Solution
{
  public:
    bool OK(LL x, LL n, LL index, LL maxSum)
    {
        LL a = x <= index ? x * (1 + x) / 2 + (index + 1 - x) : (index + 1) * (x + x - index) / 2;
        LL b = x <= n - index ? x * (x + 1) / 2 + (n - index - x) : (n - index) * (x + x - (n - index) + 1) / 2;
        LL tot = a + b - x;
        // std::cout << "x : " << x << " a : " << a << " b : " <<  b <<  " tot: " <<  tot << std::endl;
        return tot <= maxSum;
    };
    int maxValue(int n, int index, int maxSum)
    {
        /* if x <= index : a = x * (1 + x) / 2 + (index + 1 - x) * 1
         * else : a = (index + 1) * (x + x - index) / 2
         * if x <= n - index : b = x * (x + 1) / 2 + (n - index - x) * 1;
         * else : b = (n - index) * (x + x - (n - index) + 1) / 2;
         */

        int left = 1, right = 1e9, mid, ans = 0;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (OK(mid, n, index, maxSum))
                left = mid + 1;
            else
                right = mid - 1;
        };
        return right;
    }
};