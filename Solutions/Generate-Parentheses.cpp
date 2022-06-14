#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<string> res;
    void get(string cur, int left, int right)
    {
        if (left == 0 && right == 0 && validate(cur))
            res.push_back(cur);

        if (left != 0)
            get(cur + '(', left - 1, right);
        if (right != 0)
            get(cur + ')', left, right - 1);

        return;
    };
    bool validate(string cur)
    {
        int n = cur.size();
        stack<char> ans;
        for (int i = 0; i < n; i++)
        {
            if (cur[i] == '(')
                ans.push('(');
            else
            {
                if (ans.empty())
                    return false;
                else
                    ans.pop();
            };
        };
        return ans.empty();
    }
    vector<string> generateParenthesis(int n)
    {
        get("", n, n);
        return res;
    }
};