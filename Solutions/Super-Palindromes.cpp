/* 构造回文数，计算它的平方，如果在范围内且也是回文数则记录在数组中 */

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
  int64_t reverse_int(int64_t x) {
    int64_t ans = 0;
    while (x > 0) {
      ans = 10 * ans + x % 10;
      x /= 10;
    };
    return ans;
  };
  bool judge(int64_t x) {
    return x == reverse_int(x);
  };
  int superpalindromesInRange(string left, string right) {
     int n = 100000, UP = (int)1e9 + 7;
     int64_t l = stoll(left), r = stoll(right), cnt = 0;
     for (int i = 1; i < n; i++) {
       string ori = to_string(i);
       string rev = ori; reverse(rev.begin(), rev.end());
       string str1 = ori + rev;
       int64_t num1 = stoll(str1);
       if (num1 < UP) {
         num1 = num1 * num1;
         if (l <= num1 && num1 <= r) cnt += judge(num1);
         else if (l > r) break;
       } else break;
     };
     for (int i = 1; i < n; i++) {
       string ori = to_string(i);
       string rev = ori; reverse(rev.begin(), rev.end());
       string str2 = ori.substr(0, ori.size() - 1) + rev;
       int64_t num2 = stoll(str2);
       if (num2 < UP) {
         num2 = num2 * num2;
         if (l <= num2 && num2 <= r) cnt += judge(num2);
         else if (l > r) break;
       } else break;
     };
     return cnt;
  };
};