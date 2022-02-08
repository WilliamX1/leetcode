/* 遍历每个子字符串，然后判断随后截取长度相同的子字符串是否与当前子字符串相等即可，*/
/* 时间复杂度：O(N^2)，空间复杂度：O(1) */
/* 测试用例：text = "aabcaabc" ans = 3 */

#include <string>
#include <set>
#include <functional>
#include <iostream>

using namespace std;

class Solution{
public:
  int distinctEchoSubstrings(string text) {
    int len = text.size();
    set<string> s;
    std::hash<std::string> h;
    for (int i = 0; i < len; i++) {
      string str1 = "", str2 = "";
      for (int j = i; j < len; j++) {
        int sublen = j - i + 1;
        int sub_start = j + 1;
        int sub_end = j + 1 + sublen - 1;
        if (sub_end >= len) continue;
        else {
          str1 = str1 + text[j];
          str2 = str2 + text[sub_end - 1] + text[sub_end];
          size_t hash1 = h(str1 + str1);
          size_t hash2 = h(str2);
          if (hash1 == hash2) s.insert(str1);
        };
      };
    }
    return s.size();
  };
};