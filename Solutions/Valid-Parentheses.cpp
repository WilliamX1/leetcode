#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        /*如果长度为奇数肯定是错误的*/
        if (s.length() % 2 == 1) return false;

        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
            if (stk.empty()) stk.push(s[i]);
            else {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
                else if (s[i] == ')') {
                    if (stk.top() == '(') stk.pop();
                    else return false;
                } else if (s[i] == ']') {
                    if (stk.top() == '[') stk.pop();
                    else return false;
                } else if (s[i] == '}') {
                    if (stk.top() == '{') stk.pop();
                    else return false;
                }
            }
        return stk.empty();
    }
};

int main()
{
    return 0;
}