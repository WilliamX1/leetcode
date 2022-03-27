class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> stk;
        for (const char& ch : s)
            if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z') stk.push(ch);
        string ans(s.size(), '0');
        for (int i = 0; i < s.size(); i++) {
            if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z') {
                ans[i] = stk.top();
                stk.pop();
            } else ans[i] = s[i];
        };
        return ans;
    }
};