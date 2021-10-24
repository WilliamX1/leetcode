#include<bits/stdc++.h>
using namespace std;


int main(void){
    string s;
    cin>>s;
//    # your code
    stack<char> s1;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9') ans += s[i];
        else if (s[i] == '(') s1.push(s[i]);
        else if (s[i] == ')') {
            while (!s1.empty() && s1.top() != '(') {
                ans += s1.top();
                s1.pop();
            };
            s1.pop();
        } else if (s[i] == '*') {
            while (!s1.empty() && s1.top() != '(' && s1.top() != '+') {
                ans += s1.top();
                s1.pop();
            };
            s1.push(s[i]);
        } else if (s[i] == '+') {
            while (!s1.empty() && s1.top() != '(') {
                ans += s1.top();
                s1.pop();
            };
            s1.push(s[i]);
        };
    };
    while (!s1.empty()) {
        ans += s1.top();
        s1.pop();
    };
    // cout or printf
    cout << ans << endl;
    return 0;
}

//2+(1+5*6)*4
//2156*+4*+
