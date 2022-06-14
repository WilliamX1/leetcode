
/* 先分别统计这两对字符串中这两种格式的对儿 <x, y> 和 <y, x> 有多少 */
/* 然后如果 <x, y> 的数量和 <y, x> 的数量之和是奇数，则直接返回 -1 */
/* 否则如果每个都是偶数，则返回和的一半。如果每个都是奇数，则返回和的一半 + 1 */

/* 构造测试样例：
 * s1 = "xxx", s2 = "yyy", answer = -1.
 * s1 = "xyyx", s2 = "yxxy", answer = 2.
 */

#include <string>

class Solution
{
  public:
    int minimumSwap(string s1, string s2)
    {
        int cnt1 = 0, cnt2 = 0;
        int len = s1.size(); /* len = 4 */
        for (int i = 0; i < len; i++)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
                cnt1++;
            else if (s1[i] == 'y' && s2[i] == 'x')
                cnt2++;
            else
            {
            };
        }; /* cnt1 = 2, cnt2 = 2 */
        int ans = (cnt1 + cnt2) & 1 ? -1 : ((cnt1 + cnt2) >> 1) + (cnt1 & 1);
        return ans; /* ans = 2 */
    };
};