/* 动态规划，遍历整个数组，用两个变量记录当前篮子里水果的位置信息并不断更新，直到遇到一个水果和这两个都不相同，那么就需要把位置信息最小的那个水果替换掉
* 同时维持一个 tot 来记录当前收集的这两种水果的最大数目。
* 特殊考虑成环，需要重复这个数组的遍历
*/

/* 测试用例：fruits = [0, 0, 1, 1] ans = 4 */
/* 时间复杂度：O(N), 空间复杂度：O(1) */

#include <vector>

using namespace std;

class Solution{
public:
  int totalFruit(vector<int>& fruits){
    int end1 = -1, end2 = -1, start1 = -1, start2 = -1, tot1 = 0, tot2 = 0, ans = 0;
    for (int i = 0; i < fruits.size(); i++) {      
      // tot1 = 2
      // tot2 = 0
      // start1 = 0
      // end1 = 1
      // start2 = 2
      // end2 = 2
      // ans = 2
      if (end1 >= 0 && fruits[i] == fruits[end1]) {
        tot1++;
        end1 = i;
      } else if (end2 >= 0 && fruits[i] == fruits[end2]) {
        tot2++;
        end2 = i; 
      } else if (end1 <= end2) {
        tot1 = 1;
        tot2 = i - end1 - 1;
        start1 = end1 = i;
      } else {
        tot2 = 1;
        tot1 = i - end2 - 1;
        start2 = end2 = i;
      };
      ans = max(ans, tot1 + tot2);
    };
    return ans;
  };
};