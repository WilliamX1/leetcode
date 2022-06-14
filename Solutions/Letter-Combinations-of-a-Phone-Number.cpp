#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<string> res;
    vector<char> phonenum_to_char(int x)
    {
        switch (x)
        {
        case 2:
            return {'a', 'b', 'c'};
        case 3:
            return {'d', 'e', 'f'};
        case 4:
            return {'g', 'h', 'i'};
        case 5:
            return {'j', 'k', 'l'};
        case 6:
            return {'m', 'n', 'o'};
        case 7:
            return {'p', 'q', 'r', 's'};
        case 8:
            return {'t', 'u', 'v'};
        case 9:
            return {'w', 'x', 'y', 'z'};
        default:
            return {};
        };
    }
    void dfs(vector<vector<char>> &v, int n, string cur, int i)
    {
        if (i == n)
        {
            if (cur != "")
                res.push_back(cur);
            return;
        }
        for (int j = 0; j < v[i].size(); j++)
        {
            dfs(v, n, cur + v[i][j], i + 1);
        };
        return;
    }
    vector<string> letterCombinations(string digits)
    {
        int n = digits.length();
        vector<vector<char>> v(n);

        for (int i = 0; i < n; i++)
            v[i] = phonenum_to_char(digits[i] - '0');

        dfs(v, n, "", 0);
        return res;
    }
};