#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    string modifyString(string s)
    {
        int n = s.length();
        s = ' ' + s + ' ';
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '?')
            {
                char ch = 'a';
                while (s[i - 1] == ch || s[i + 1] == ch)
                    ch++;
                s[i] = ch;
            }
        };
        return s.substr(1, n);
    }
};