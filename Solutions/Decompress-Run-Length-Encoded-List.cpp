/* 遍历原来数组，每次将奇数位上的数量的偶数位上的值压入结果数组，返回即可 */
/* 测试用例：v = {1 3 2 4 5 2}, ans = {3 4 4 2 2 2 2 2} */
/* 时间复杂度：O(N * max(nums)) 空间复杂度：O(N * max(nums)) */

#include <vector>

using namespace std;

class Solution{
public:
  vector<int> decompressRLElist(vector<int>& nums){
    vector<int> ans;
    int len = nums.size();
    for (int i = 0; i < len; i += 2) {
      for (int j = 0; j < nums[i]; j++) {
          ans.push_back(nums[i + 1]);
      };
    };
    return ans;
  };
};