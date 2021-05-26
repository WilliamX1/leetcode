#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        /* 栈版逆转 */
        // deque<char> ans, que;
        // for (int i = 0; s[i] != '\0'; i++)
        // {
        //     if (s[i] == ')') {
        //         while (!ans.empty()) {
        //             if (ans.back() == '(') {
        //                 ans.pop_back();
        //                 break;
        //             } else {
        //                 que.push_back(ans.back());
        //                 ans.pop_back();
        //             };
        //         };
        //         while (!que.empty()) {
        //             ans.push_back(que.front());
        //             que.pop_front();
        //         };
        //     } else {
        //         ans.push_back(s[i]);
        //     }
        // };
        // string res = "";
        // while (!ans.empty()) {
        //     res += ans.front();
        //     ans.pop_front();
        // };
        // return res;
        /* 数组版逆转 */
        stack<int> left_bracket;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') left_bracket.push(i);
            else if (s[i] == ')') {
                int left = left_bracket.top(), right = i;
                left_bracket.pop();
                int mid = (left + right) >> 1;
                char tmp = 0;
                /* 交换 */
                for (int j = 1; j <= mid - left; j++) {
                    tmp = s[left + j];
                    s[left + j] = s[right - j];
                    s[right - j] = tmp;
                }
            } else continue;
        };
        s.erase(remove(s.begin(), s.end(), '('), s.end());
        s.erase(remove(s.begin(), s.end(), ')'), s.end());
        return s;
    }
};