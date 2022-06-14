/* 先统计出所有的奇数数字的位置，然后以 k 为大小的滑动窗口去遍历
 * 这样就能算出恰好含有 k 个奇数数字的 “极小” 子数组，然后再去看两侧奇数的位置，相乘就可以算出含有部分 “多余偶数”
 * 的数组有多少个
 */

/* 测试用例, nums = <1 1 2 1 1>, k = 2, ans = 5 */
/* 时间复杂度: O(N), 空间复杂度: O(N) */
#include <vector>

using namespace std;

class Solution
{
  public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        /* nums: 1 1 2 1 1 */
        int len = nums.size();
        vector<int> v;
        v.push_back(-1);
        for (int i = 0; i < len; i++)
            if (nums[i] & 1)
            {
                v.push_back(i);
            };
        v.push_back(len);
        /* v: -1 0 1 3 4 5 */
        int ans = 0;
        for (int start = 1; start < v.size(); start++)
        {
            int end = start + k - 1;
            if (end >= v.size() - 1)
                break;
            else
                ans += (v[start] - v[start - 1]) * (v[end + 1] - v[end]); /* ans += 2 += 1 += 2 = 5 */
        };
        return ans;
    };
};