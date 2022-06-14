#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    string reverseStr(string s, int k)
    {
        string res = "";
        int len = s.size(), idx = 0;
        while (idx < len)
        {
            reverse(s.begin() + idx, idx + k < len ? s.begin() + idx + k : s.end());
            res += s.substr(idx, k << 1);
            idx += k << 1;
        };
        return res;
    }
};