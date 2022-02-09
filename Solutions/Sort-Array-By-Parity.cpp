/* 遍历整个数组，将所有偶数和奇数元素分别取出成为单独的数组，然后再进行拼接即可 */
/* 测试用例：nums = {2,1,4,3} */
/* 时间复杂度：O(N)，空间复杂度：O(N) */

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> odds, evens, ans;
    /* odds = {1, 3} evens = {2, 4} */
    for (auto& num : nums)
      if (num & 1) odds.push_back(num);
      else evens.push_back(num);
    for (auto &num : evens)
      ans.push_back(num); // ans = {2, 4}
    for (auto &num : odds)
      ans.push_back(num); // ans = {2, 4, 1, 3}
    return ans; 
  };
};